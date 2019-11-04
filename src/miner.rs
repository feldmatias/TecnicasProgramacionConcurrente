
use crate::leader::leader_signal::LeaderSignal;
use crate::leader::leader_ask_prize_signal::LeaderAskPrizeSignal;
use crate::leader::leader_prize_channel::LeaderPrizeSender;

pub struct Miner {
    pub leader_signal: LeaderSignal,
    pub leader_ask_prize_signal: LeaderAskPrizeSignal,
    pub prize_sender: LeaderPrizeSender,
    pub number: i32
}

impl Miner {
    pub fn start(&self) {
        self.mine();
        self.share_prize();
    }

    fn mine(&self) {
        self.leader_signal.wait();

        while self.leader_signal.should_continue() {

        }

        println!("miner {} started and did work", self.number);
    }

    fn share_prize(&self) {
        self.leader_ask_prize_signal.wait();
        self.prize_sender.send(123);
    }
}