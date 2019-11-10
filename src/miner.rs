use crate::logger::Logger;
use crate::synchronization::SyncData;
use crate::synchronization::channel::message::{Message, TIE, WINNER, LOSER};
use crate::leader::time_simulator::TimeSimulator;
use crate::miner::miner_data::MinerData;

pub mod miner_data;

pub struct Miner {
    pub logger: Logger,
    pub sync: SyncData,
    pub number: usize,
    pub data: MinerData
}

impl Miner {

    pub fn create(sync: SyncData, number: usize, logger: Logger) -> Miner {
        return Miner {
            logger: logger,
            sync: sync,
            number: number,
            data: MinerData::default()
        };
    }

    pub fn start(&mut self) {
        while self.sync.should_continue() {
            self.mine();
            self.share_prize();
            let should_continue = self.end_round();
            self.sync.end_round();
            if !should_continue {
                break;
            }
        }
    }

    fn mine(&mut self) {
        self.sync.leader_signal.wait();

        while self.sync.leader_signal.should_continue() {
            TimeSimulator::simulate_time_between(10, 200);
            self.data.current_mines += 1;
        }

        self.sync.barrier.wait(self.sync.len());
    }

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

    fn end_round(&mut self) -> bool {
        let msg = self.sync.receiver.receive();

        if msg.data == TIE {
            self.data.set_total();
            self.sync.barrier.wait(self.sync.len());
            return true;
        }

        if msg.data == WINNER {
            self.data.set_total();
            let prize = self.sync.receiver.receive();
            self.logger.log(format!("Miner {}: Received prize {} from miner {}", self.number, prize.data, prize.miner));
            self.data.add_earned(prize.data as usize);
            self.sync.remove(prize.miner);
            self.sync.barrier.wait(self.sync.len());
            return true;
        }

        if msg.data == LOSER {
            self.sync.remove(msg.miner);
            if msg.miner != self.number {
                self.data.set_total();
                self.sync.barrier.wait(self.sync.len());
                return true;
            }

            self.logger.log(format!("Miner {}: I lost and will retire.", self.number));
            self.loser();

            return false;
        }

        return false;
    }

    fn loser(&mut self) {
        let winners_count = self.sync.receiver.receive().data;
        self.logger.log(format!("Miner {}: Sending total prize of {} to {} winners.", self.number, self.data.current_mines , winners_count));

        let prize = self.data.current_mines / winners_count as usize;

        for _ in 0..winners_count {
            let winner = self.sync.receiver.receive().data as usize;
            self.logger.log(format!("Miner {}: Sending prize {} to winner {}.", self.number, prize , winner));
            self.sync.senders.send_to(winner, Message::create(self.number, prize as i32));
        }

        self.data.set_total();
    }
}