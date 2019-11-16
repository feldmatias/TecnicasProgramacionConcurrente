use crate::synchronization::channel::ChannelSender;
use crate::synchronization::channel::message::Message;

/**
 * Class that contains all channel senders.
 */
pub struct ChannelSendersList {
    pub senders: Vec<ChannelSender>,
    pub number: usize,
    pub losers: Vec<usize>
}

impl ChannelSendersList {

    /**
     * Send a message through all channels.
     */
    pub fn send_to_all(&self, msg : Message) {
        for (i, sender) in self.senders.iter().enumerate() {
            if i != self.number && !self.losers.contains(&i) {
                sender.send(msg)
            }
        }
    }

    /**
     * Send a message through a specific channel.
     */
    pub fn send_to(&self, receiver: usize, msg : Message) {
        self.senders[receiver].send(msg);
    }

    /**
     * Add a new channel.
     */
    pub fn add(&mut self, sender: ChannelSender) {
        self.senders.push(sender);
    }

    /**
     * How many channels are active.
     */
    pub fn len(&self) -> usize {
        return self.senders.len() - self.losers.len();
    }

    /**
     * Set a channel as inactive.
     */
    pub fn remove(&mut self, i: usize) {
        self.losers.push(i);
    }
}

impl Clone for ChannelSendersList {
    /**
     * Clone the channels list.
     */
    fn clone(&self) -> ChannelSendersList {
        let mut list = ChannelSendersList {
            senders: vec![],
            number: self.number,
            losers: self.losers.clone()
        };

        for sender in &self.senders {
            list.senders.push(sender.clone());
        }

        return list;
    }
}

impl Default for ChannelSendersList {

    /**
     * Create an empty channels list.
     */
    fn default() -> Self {
        return ChannelSendersList {
            senders: vec![],
            number: 0,
            losers: vec![]
        }
    }
}