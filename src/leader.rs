use std::thread;
use std::time::Duration;

pub mod leader_signal;
use self::leader_signal::LeaderSignal;

pub mod leader_channel;
use crate::leader::leader_channel::{ChannelReceiver, ChannelSender};
use crate::logger::Logger;

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
        self.ask_miners_prize();
    }

    fn let_miners_mine(&mut self) {
        self.logger.log(format!("Round Started"));
        self.leader_signal.signal_start();

        thread::sleep(Duration::from_secs(2));

        self.leader_signal.signal_end();

        // Wait for miners to receive the signal
        for _ in 0..self.miner_channels.len() {
            let _ = self.receiver.receive_signal();
        }
        self.logger.log(format!("Round Ended"));
    }

    fn ask_miners_prize(&mut self) {
        for (i, channel) in self.miner_channels.iter().enumerate() {
            channel.send_signal();
            let prize = self.receiver.receive();
            self.logger.log(format!("Leader: received {} from miner {}", prize, i));
        }
    }
}