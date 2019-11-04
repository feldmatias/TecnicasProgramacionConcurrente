use std::thread;
use std::time::Duration;

pub mod leader_signal;
use self::leader_signal::LeaderSignal;

pub mod leader_ask_prize_signal;
use self::leader_ask_prize_signal::LeaderAskPrizeSignal;
use crate::leader::leader_prize_channel::LeaderPrizeReceiver;
use crate::logger::Logger;

pub mod leader_prize_channel;

pub struct Leader {
    pub leader_signal: LeaderSignal,
    pub prize_receiver: LeaderPrizeReceiver,
    pub logger: Logger
}

impl Leader {
    pub fn start(&mut self, ask_prize_signals: Vec<LeaderAskPrizeSignal>) {
        thread::sleep(Duration::from_secs(1));

        self.let_miners_mine(ask_prize_signals.len());
        self.ask_miners_prize(ask_prize_signals);
    }

    fn let_miners_mine(&mut self, miners: usize) {
        self.logger.log(format!("Round Started"));
        self.leader_signal.signal_start();

        thread::sleep(Duration::from_secs(2));

        self.leader_signal.signal_end();

        // Wait for miners to receive the signal
        for _ in 0..miners {
            let _ = self.prize_receiver.receive();
        }
        self.logger.log(format!("Round Ended"));
    }

    fn ask_miners_prize(&mut self, ask_prize_signals: Vec<LeaderAskPrizeSignal>) {
        for (i, signal) in ask_prize_signals.iter().enumerate() {
            signal.ask_prize();
            let prize = self.prize_receiver.receive();
            self.logger.log(format!("leader received {} from miner {}", prize, i));
        }
    }
}