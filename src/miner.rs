
use crate::leader::leader_signal::LeaderSignal;
use crate::leader::leader_channel::{ChannelSender, ChannelReceiver};

pub struct MinerData {
    current_mines : i32
    // Todo add other data: total mines, total earned mines
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
    pub receiver: ChannelReceiver,
    pub sender: ChannelSender,
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

        self.sender.send_signal();
    }

    fn share_prize(&self) {
        self.receiver.receive_signal();
        self.sender.send(self.data.current_mines);
    }
}