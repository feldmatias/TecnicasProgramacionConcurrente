use crate::logger::Logger;
use crate::synchronization::SyncData;
use crate::synchronization::channel::message::{Message, TIE, WINNER, LOSER, FINAL_RESULT};
use crate::leader::time_simulator::TimeSimulator;
use crate::miner::miner_data::MinerData;
use crate::leader::LEADER_NUMBER;

pub mod miner_data;

/**
 * Class that represents a miner.
 */
pub struct Miner {
    pub logger: Logger,
    pub sync: SyncData,
    pub number: usize,
    pub data: MinerData
}

impl Miner {

    /**
     * Create a miner.
     */
    pub fn create(sync: SyncData, number: usize, logger: Logger) -> Miner {
        return Miner {
            logger: logger,
            sync: sync,
            number: number,
            data: MinerData::default()
        };
    }

    /**
     * Let the miner start working.
     */
    pub fn start(&mut self) {
        while self.sync.should_continue(self.number) {
            self.mine();
            self.share_prize();
            self.end_round();
            self.sync.end_round();
        }
        self.end_game();
    }

    /**
     * Start mining until stop signal received.
     */
    fn mine(&mut self) {
        self.sync.leader_signal.wait();

        while self.sync.leader_signal.should_continue() {
            TimeSimulator::simulate_time_between(10, 200);
            self.data.current_mines += 1;
        }

        self.sync.barrier.wait(self.sync.len());
    }

    /**
     * Share round prizes with all the other miners.
     */
    fn share_prize(&mut self) {
        for i in 1..self.sync.initial_count {
            if self.sync.is_loser(i) {
                continue;
            }

            if i == self.number {
                self.logger.log(format!("Miner {}: Shouting prize {}", self.number, self.data.current_mines));
                self.sync.senders.send_to_all(Message::create(self.number, self.data.current_mines as i32));
            } else {
                let msg = self.sync.receiver.receive();
                self.logger.log(format!("Miner {}: Heard prize {} from miner {}", self.number, msg.data, msg.miner));
            }

            self.sync.barrier.wait(self.sync.len());
        }
    }

    /**
     * Finish the current round. Receive round results from leader.
     */
    fn end_round(&mut self) {
        let msg = self.sync.receiver.receive();

        if msg.data == TIE {
            self.data.set_total();
            self.sync.barrier.wait(self.sync.len());
            return;
        }

        if msg.data == WINNER {
            self.data.set_total();
            let prize = self.sync.receiver.receive();
            self.logger.log(format!("Miner {}: Received prize {} from miner {}", self.number, prize.data, prize.miner));
            self.data.add_earned(prize.data as usize);
            self.sync.remove(prize.miner);
            self.sync.barrier.wait(self.sync.len());
            return;
        }

        if msg.data == LOSER {
            self.sync.remove(msg.miner);
            if msg.miner != self.number {
                self.data.set_total();
                self.sync.barrier.wait(self.sync.len());
                return;
            }

            self.logger.log(format!("Miner {}: I lost and will retire.", self.number));
            self.loser();

            return;
        }

        return;
    }

    /**
     * Miner lost the round. Send prize to winners.
     */
    fn loser(&mut self) {
        let winners_count = self.sync.receiver.receive().data;
        self.logger.log(format!("Miner {}: I will send a total prize of {} to {} winners", self.number, self.data.current_mines , winners_count));

        let prize = self.data.current_mines / winners_count as usize;

        for _ in 0..winners_count {
            let winner = self.sync.receiver.receive().data as usize;
            self.logger.log(format!("Miner {}: Sending prize {} to winner {}", self.number, prize , winner));
            self.sync.senders.send_to(winner, Message::create(self.number, prize as i32));
        }

        self.data.set_total();
    }

    /**
     * Send game results to leader.
     */
    fn end_game(&self) {
        loop {
            let signal = self.sync.receiver.receive();
            if signal.data == FINAL_RESULT {
                break;
            }
        }

        let round_lost : i32 = if self.sync.is_loser(self.number) {self.sync.current_round as i32 - 1} else { -1 };
        self.sync.senders.send_to(LEADER_NUMBER, Message::create(self.number, round_lost));
        self.sync.senders.send_to(LEADER_NUMBER, Message::create(self.number, self.data.total_mined as i32));
        self.sync.senders.send_to(LEADER_NUMBER, Message::create(self.number, self.data.total_earned as i32));
    }
}