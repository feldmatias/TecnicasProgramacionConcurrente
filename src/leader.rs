use std::thread;
use std::time::Duration;

pub mod leader_signal;
use self::leader_signal::LeaderSignal;

pub mod leader_channel;
use crate::leader::leader_channel::{ChannelReceiver, ChannelSender};
use crate::logger::Logger;
use crate::leader::miner_prize::{MinerPrize, MINER_EQUAL_PRIZES};

pub mod miner_prize;

pub struct Leader {
    pub leader_signal: LeaderSignal,
    pub receiver: ChannelReceiver,
    pub logger: Logger,
    pub miner_channels: Vec<ChannelSender>
}

impl Leader {
    pub fn start(&mut self) {
        thread::sleep(Duration::from_secs(1)); // TODO: change this and add while loop

        self.let_miners_mine();
        let prizes = self.ask_miners_prize();
        let loser = self.get_miner_loser(&prizes);
        let winners = self.get_miner_winners(&prizes);
    }

    fn let_miners_mine(&mut self) {
        self.logger.log(format!("Round Started"));
        self.leader_signal.signal_start();

        thread::sleep(Duration::from_secs(2));

        self.leader_signal.signal_end();

        // Wait for all miners to receive the end signal
        for _ in 0..self.miner_channels.len() {
            self.receiver.receive_signal();
        }
        self.logger.log(format!("Round Ended"));
    }

    fn ask_miners_prize(&mut self) -> Vec<MinerPrize> {
        let mut prizes = vec![];

        for (i, channel) in self.miner_channels.iter().enumerate() {
            channel.send_signal();
            let prize = self.receiver.receive();
            self.logger.log(format!("Leader: received {} from miner {}", prize, i));

            prizes.push(MinerPrize {
                miner_number: i as i32,
                miner_prize: prize
            })
        }

        return prizes;
    }

    fn get_miner_loser(&mut self, prizes: &Vec<MinerPrize>) -> MinerPrize {
        let mut min = MinerPrize::default();

        for prize in prizes {
            if prize.miner_prize < min.miner_prize {
                min = *prize;
            } else if prize.miner_prize == min.miner_prize {
                min.miner_number = MINER_EQUAL_PRIZES;
            }
        }

        if min.miner_number == MINER_EQUAL_PRIZES {
            self.logger.log(format!("Tie"));
            self.logger.log(format!("2 or more miners have the same prize: {}", min.miner_prize));
        } else {
            self.logger.log(format!("Miner {} lost with {} mines", min.miner_number, min.miner_prize));
        }

        return min;
    }

    fn get_miner_winners(&mut self, prizes: &Vec<MinerPrize>) -> Vec<MinerPrize> {
        let mut winners = vec![];
        let mut max = -1;

        for prize in prizes {
            if prize.miner_prize > max {
                max = prize.miner_prize;
                winners.clear();
                winners.push(*prize);
            } else if prize.miner_prize == max {
                winners.push(*prize);
            }
        }

        self.logger.log(format!("There are {} winners", winners.len()));

        return winners;
    }
}