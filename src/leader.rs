use std::thread;
use std::time::Duration;

pub mod leader_signal;
use self::leader_signal::LeaderSignal;

pub mod leader_ask_prize_signal;
use self::leader_ask_prize_signal::LeaderAskPrizeSignal;
use crate::leader::leader_prize_channel::LeaderPrizeReceiver;

pub mod leader_prize_channel;

pub struct Leader {
    pub leader_signal: LeaderSignal,
    pub prize_receiver: LeaderPrizeReceiver
}

impl Leader {
    pub fn start(&self, ask_prize_signals: Vec<LeaderAskPrizeSignal>) {
        thread::sleep(Duration::from_secs(1));

        self.let_miners_mine();
        self.ask_miners_prize(ask_prize_signals);
    }

    fn let_miners_mine(&self) {
        self.leader_signal.signal_start();

        thread::sleep(Duration::from_secs(2));

        self.leader_signal.signal_end()
    }

    fn ask_miners_prize(&self, ask_prize_signals: Vec<LeaderAskPrizeSignal>) {
        for (i, signal) in ask_prize_signals.iter().enumerate() {
            signal.ask_prize();
            let prize = self.prize_receiver.receive();
            println!("leader received {} from miner {}",prize, i);
        }
    }
}