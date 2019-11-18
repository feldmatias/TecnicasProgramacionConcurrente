use crate::leader::miner_prize::{MinerPrize, NO_MINER};
use crate::leader::time_simulator::TimeSimulator;
use crate::logger::Logger;
use crate::synchronization::channel::message::{FINAL_RESULT, LOSER, Message, TIE, WINNER};
use crate::synchronization::SyncData;

pub mod leader_signal;

pub mod miner_prize;
pub mod time_simulator;

pub const LEADER_NUMBER: usize = 0;

/**
 * Class that represents the leader.
 */
pub struct Leader {
    pub logger: Logger,
    pub sync: SyncData,
}

impl Leader {
    /**
     * Create the leader.
     */
    pub fn create(sync: SyncData, logger: Logger) -> Leader {
        return Leader {
            sync: sync,
            logger: logger,
        };
    }

    /**
     * Let the leader start working.
     */
    pub fn start(&mut self) {
        while self.sync.should_continue(LEADER_NUMBER) {
            self.logger.log(format!("Round {} Started", self.sync.current_round));

            self.let_miners_mine();
            let prizes = self.hear_miners_prize();
            let loser = self.get_miner_loser(&prizes);
            self.analyze_results(prizes, loser);

            self.logger.log(format!("Round {} Ended", self.sync.current_round));
            self.logger.log(String::from("--------------------------------------------------"));
            self.sync.end_round();
        }

        self.end_game();
    }

    /**
     * Start a new round. Signal miners to start and stop mining.
     */
    fn let_miners_mine(&mut self) {
        self.sync.leader_signal.signal_start();

        TimeSimulator::simulate_time_between(3000, 5000);

        self.logger.log(format!("Leader: Sending signal to end round"));
        self.sync.leader_signal.signal_end();

        // Wait for all miners to receive the end signal
        self.sync.barrier.wait(self.sync.len());
    }

    /**
     * Hear all miners' prizes.
     */
    fn hear_miners_prize(&mut self) -> Vec<MinerPrize> {
        let mut prizes = vec![];

        for _ in 1..self.sync.len() {
            let prize = self.sync.receiver.receive();
            self.logger.log(format!("Leader: Heard prize {} from miner {}", prize.data, prize.miner));

            prizes.push(MinerPrize {
                miner_number: prize.miner as i32,
                miner_prize: prize.data,
            });

            self.sync.barrier.wait(self.sync.len());
        }

        return prizes;
    }

    /**
     * Calculate which miner lost the round.
     */
    fn get_miner_loser(&mut self, prizes: &Vec<MinerPrize>) -> MinerPrize {
        let loser = MinerPrize::get_loser(prizes);

        if loser.miner_number == NO_MINER {
            self.logger.log(format!("Leader: Tie"));
            self.logger.log(format!("Leader: 2 or more miners have the lowest prize {}", loser.miner_prize));
        } else {
            self.logger.log(format!("Leader: Miner {} lost with {} mines", loser.miner_number, loser.miner_prize));
        }

        return loser;
    }

    /**
     * Analyze if there are winners or it is a tie.
     */
    fn analyze_results(&mut self, prizes: Vec<MinerPrize>, loser: MinerPrize) {
        if loser.miner_number != NO_MINER {
            let winners = self.get_miner_winners(&prizes);
            self.send_result(loser, winners);
            self.sync.remove(loser.miner_number as usize);
        } else {
            self.sync.senders.send_to_all(Message::create(LEADER_NUMBER, TIE));
        }

        self.sync.barrier.wait(self.sync.len());
    }

    /**
     * Calculate the miners who won the round.
     */
    fn get_miner_winners(&mut self, prizes: &Vec<MinerPrize>) -> Vec<i32> {
        let winners = MinerPrize::get_winners(prizes);

        self.logger.log(format!("Leader: There are {} winners", winners.len()));

        return winners;
    }

    /**
     * Send round result to each miner.
     */
    fn send_result(&mut self, loser: MinerPrize, winners: Vec<i32>) {
        for i in 1..self.sync.initial_count {
            if self.sync.is_loser(i) {
                continue;
            }

            if winners.contains(&(i as i32)) {
                self.sync.senders.send_to(i as usize, Message::create(LEADER_NUMBER, WINNER));
            } else {
                self.sync.senders.send_to(i as usize, Message::create(loser.miner_number as usize, LOSER));
                if i as i32 == loser.miner_number {
                    self.send_winners_to_loser(i as usize, &winners);
                }
            }
        }
    }

    /**
     * Send which miners won to the loser.
     */
    fn send_winners_to_loser(&self, loser: usize, winners: &Vec<i32>) {
        self.sync.senders.send_to(loser, Message::create(LEADER_NUMBER, winners.len() as i32));
        for winner in winners {
            self.sync.senders.send_to(loser, Message::create(LEADER_NUMBER, *winner));
        }
    }

    /**
     * Receive game results from each miner.
     */
    fn end_game(&mut self) {
        self.logger.log(format!("Game Ended"));
        for i in 1..self.sync.initial_count {
            self.sync.senders.send_to(i as usize, Message::create(LEADER_NUMBER, FINAL_RESULT));
            let round_lost = self.sync.receiver.receive().data;
            let total_mined = self.sync.receiver.receive().data;
            let total_earned = self.sync.receiver.receive().data;

            let final_result = if round_lost > 0 { format!("Loser in round {}", round_lost) } else { format!("Winner") };
            self.logger.log(format!("Miner {} results: {} mined and {} earned. {}", i, total_mined, total_earned, final_result));
        }
    }
}