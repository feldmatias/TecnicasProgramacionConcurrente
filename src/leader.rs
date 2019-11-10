use std::thread;
use std::time::Duration;

pub mod leader_signal;

use crate::logger::Logger;
use crate::leader::miner_prize::{MinerPrize, MINER_EQUAL_PRIZES};
use crate::synchronization::SyncData;
use crate::synchronization::channel::message::{Message, TIE, LOSER, WINNER};

pub mod miner_prize;

pub const LEADER_NUMBER : usize = 0;

pub struct Leader {
    pub logger: Logger,
    pub sync: SyncData,
}

impl Leader {

    pub fn create(sync: SyncData, logger: Logger) -> Leader {
        return Leader {
            sync: sync,
            logger: logger
        };
    }

    pub fn start(&mut self) {
        thread::sleep(Duration::from_secs(1)); // TODO: change this and add while loop

        self.let_miners_mine();
        let prizes = self.hear_miners_prize();
        let loser = self.get_miner_loser(&prizes);

        if loser.miner_number != MINER_EQUAL_PRIZES {
            let winners = self.get_miner_winners(&prizes);
            self.send_result(loser, winners);
            self.sync.remove(loser.miner_number as usize);
        } else {
            self.sync.senders.send_to_all(Message::create(LEADER_NUMBER, TIE));
        }

        self.sync.barrier.wait(self.sync.len());
        self.logger.log(format!("Round Ended"));
    }

    fn let_miners_mine(&mut self) {
        self.logger.log(format!("Round Started"));
        self.sync.leader_signal.signal_start();

        thread::sleep(Duration::from_secs(2));

        self.logger.log(format!("Leader: Sending signal to end round"));
        self.sync.leader_signal.signal_end();

        // Wait for all miners to receive the end signal
        self.sync.barrier.wait(self.sync.len());
    }

    fn hear_miners_prize(&mut self) -> Vec<MinerPrize> {
        let mut prizes = vec![];

        for _ in 1..self.sync.len() {
            let prize = self.sync.receiver.receive();
            self.logger.log(format!("Leader: Heard prize {} from miner {}", prize.data, prize.miner));

            prizes.push(MinerPrize {
                miner_number: prize.miner as i32,
                miner_prize: prize.data
            });

            self.sync.barrier.wait(self.sync.len());
        }

        return prizes;
    }

    fn get_miner_loser(&mut self, prizes: &Vec<MinerPrize>) -> MinerPrize {
        let mut min = MinerPrize::get_loser(prizes);

        if min.miner_number == MINER_EQUAL_PRIZES {
            self.logger.log(format!("Leader: Tie"));
            self.logger.log(format!("Leader: 2 or more miners have the lowest prize {}", min.miner_prize));
        } else {
            self.logger.log(format!("Leader: Miner {} lost with {} mines", min.miner_number, min.miner_prize));
        }

        return min;
    }

    fn get_miner_winners(&mut self, prizes: &Vec<MinerPrize>) -> Vec<i32> {
        let mut winners = MinerPrize::get_winners(prizes);

        self.logger.log(format!("Leader: There are {} winners", winners.len()));

        return winners;
    }

    fn send_result(&mut self, loser : MinerPrize, winners : Vec<i32>) {
        let prize = loser.miner_prize / winners.len() as i32;

        for i in 1..11 { //TODO do not hardcode 11
            if winners.contains(&i) {
                self.sync.senders.send_to(i as usize, Message::create(LEADER_NUMBER, WINNER));
            } else {
                self.sync.senders.send_to(i as usize, Message::create(loser.miner_number as usize, LOSER));
                if i == loser.miner_number {
                    self.sync.senders.send_to(i as usize, Message::create(winners[0] as usize, winners[0])); //TODO send to all winners
                }
            }
        }
    }
}