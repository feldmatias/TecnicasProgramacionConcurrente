
use crate::leader::leader_signal::LeaderSignal;
use crate::leader::leader_ask_prize_signal::LeaderAskPrizeSignal;
use crate::leader::leader_prize_channel::LeaderPrizeSender;

pub struct MinerData {
    current_mines : i32
}

impl Default for MinerData {
    fn default() -> Self {
        return MinerData {
            current_mines: 0
        }
    }
}

pub struct Miner {
    pub leader_signal: LeaderSignal,
    pub leader_ask_prize_signal: LeaderAskPrizeSignal,
    pub prize_sender: LeaderPrizeSender,
    pub number: i32,
    pub data: MinerData
}

impl Miner {
    pub fn start(&mut self) {
        self.mine();
        self.share_prize();
    }

    fn mine(&mut self) {
        self.leader_signal.wait();

        while self.leader_signal.should_continue() {
            self.data.current_mines += 1;
        }

        self.prize_sender.send(-1);
        println!("miner {} started and did work", self.number);
    }

    fn share_prize(&self) {
        self.leader_ask_prize_signal.wait();
        self.prize_sender.send(self.data.current_mines);
    }
}