use std::thread;
use std::time::Duration;

use crate::leader::leader_signal::LeaderSignal;

pub struct Miner {
    start_signal: LeaderSignal,
    number: i32
}

impl Miner {
    pub fn create(signal: LeaderSignal, i : i32) -> Miner {
        let miner = Miner {
            start_signal: signal,
            number: i
        };

        return miner;
    }

    pub fn start(&self) {
        self.start_signal.wait();

        thread::sleep(Duration::from_millis(100));
        println!("miner {} started and did work", self.number);
    }
}