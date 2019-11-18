use crate::config::Config;
use crate::leader::leader_signal::LeaderSignal;
use crate::synchronization::barrier::Barrier;
use crate::synchronization::channel::{ChannelReceiver, create_channel};
use crate::synchronization::channel::channel_senders_list::ChannelSendersList;

pub mod barrier;
pub mod channel;

/**
 * Class that initializes all sync resources.
 */
pub struct SyncInfo {
    leader_signal: LeaderSignal,
    barrier: Barrier,
    receivers: Vec<ChannelReceiver>,
    senders: ChannelSendersList,
    rounds: usize,
}

impl SyncInfo {
    /**
     * Initialize sync resources.
     */
    pub fn initialize(config: &Config) -> SyncInfo {
        let mut sync = SyncInfo {
            leader_signal: LeaderSignal::create(),
            barrier: Barrier::create(),
            receivers: vec![],
            senders: ChannelSendersList::default(),
            rounds: config.rounds,
        };

        for _ in 0..config.miners + 1 {
            let (rx, tx) = create_channel();
            sync.senders.add(tx);
            sync.receivers.push(rx);
        }

        return sync;
    }

    /**
     * Get sync resources for person i.
     */
    pub fn data_for(&mut self, i: usize) -> SyncData {
        let mut sync = SyncData {
            leader_signal: self.leader_signal.clone(),
            barrier: self.barrier.clone(),
            receiver: self.receivers.remove(0),
            senders: self.senders.clone(),
            initial_count: self.senders.len(),
            rounds_left: self.rounds,
            current_round: 1,
        };

        sync.senders.number = i;
        return sync;
    }
}

/**
 * Class that contains all sync resources.
 */
pub struct SyncData {
    pub leader_signal: LeaderSignal,
    pub barrier: Barrier,
    pub receiver: ChannelReceiver,
    pub senders: ChannelSendersList,
    pub initial_count: usize,
    pub rounds_left: usize,
    pub current_round: usize,
}

impl SyncData {
    /**
     * How many persons are still in the game.
     */
    pub fn len(&self) -> usize {
        return self.senders.len();
    }

    /**
     * Remove a person from a game.
     */
    pub fn remove(&mut self, i: usize) {
        self.senders.remove(i);
    }

    /**
     * If the game has another round or not.
     */
    pub fn should_continue(&self, i: usize) -> bool {
        return !self.is_loser(i) && self.rounds_left > 0 && self.len() > 2; // Leader and more than 1 miner
    }

    /**
     * If current miner is a loser or not.
     */
    pub fn is_loser(&self, i: usize) -> bool {
        return self.senders.losers.contains(&i);
    }

    /**
     * End a round.
     */
    pub fn end_round(&mut self) {
        self.rounds_left -= 1;
        self.current_round += 1;
    }
}
