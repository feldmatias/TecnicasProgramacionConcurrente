use crate::leader::leader_signal::LeaderSignal;
use crate::synchronization::barrier::Barrier;
use crate::synchronization::channel::{ChannelReceiver, create_channel};
use crate::synchronization::channel::channel_senders_list::ChannelSendersList;

pub mod barrier;
pub mod channel;

pub struct SyncInfo {
    leader_signal: LeaderSignal,
    barrier: Barrier,
    receivers: Vec<ChannelReceiver>,
    senders: ChannelSendersList,
    rounds: usize
}

impl SyncInfo {

    pub fn initialize(n: usize, rounds: usize) -> SyncInfo {
        let mut sync = SyncInfo {
            leader_signal: LeaderSignal::create(),
            barrier: Barrier::create(),
            receivers: vec![],
            senders: ChannelSendersList::default(),
            rounds: rounds
        };

        for _ in 0..n {
            let (rx, tx) = create_channel();
            sync.senders.add(tx);
            sync.receivers.push(rx);
        }

        return sync;
    }

    pub fn data_for(&mut self, i: usize) -> SyncData {
        let mut sync = SyncData {
            leader_signal: self.leader_signal.clone(),
            barrier: self.barrier.clone(),
            receiver: self.receivers.remove(0),
            senders: self.senders.clone(),
            initial_count: self.senders.len(),
            rounds: self.rounds
        };

        sync.senders.number = i;
        return sync;
    }
}

pub struct SyncData {
    pub leader_signal: LeaderSignal,
    pub barrier: Barrier,
    pub receiver: ChannelReceiver,
    pub senders: ChannelSendersList,
    pub initial_count: usize,
    pub rounds: usize
}

impl SyncData {
    pub fn len(&self) -> usize {
        return self.senders.len();
    }

    pub fn remove(&mut self, i: usize) {
        self.senders.remove(i);
    }

    pub fn should_continue(&self, i: usize) -> bool {
        return !self.is_loser(i) && self.rounds > 0 && self.len() > 2; // Leader and more than 1 miner
    }

    pub fn is_loser(&self, i: usize) -> bool {
        return self.senders.losers.contains(&i);
    }

    pub fn end_round(&mut self) {
        self.rounds -= 1;
    }
}
