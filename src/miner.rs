
use crate::leader::leader_signal::LeaderSignal;

pub struct Miner {
    leader_signal: LeaderSignal,
    number: i32
}

impl Miner {
    pub fn create(signal: LeaderSignal, number : i32) -> Miner {
        let miner = Miner {
            leader_signal: signal,
            number: number
        };

        return miner;
    }

    pub fn start(&self) {
        self.mine();
    }

    fn mine(&self) {
        self.leader_signal.wait();

        while self.leader_signal.should_continue() {

        }

        println!("miner {} started and did work", self.number);
    }
}