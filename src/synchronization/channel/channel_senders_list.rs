use crate::synchronization::channel::ChannelSender;
use crate::synchronization::channel::message::Message;

pub struct ChannelSendersList {
    pub senders: Vec<ChannelSender>,
    pub number: usize,
    pub losers: Vec<usize>
}

impl ChannelSendersList {

    pub fn send_to_all(&self, msg : Message) {
        for (i, sender) in self.senders.iter().enumerate() {
            if i != self.number && !self.losers.contains(&i) {
                sender.send(msg)
            }
        }
    }

    pub fn send_to(&self, receiver: usize, msg : Message) {
        self.senders[receiver].send(msg);
    }

    pub fn add(&mut self, sender: ChannelSender) {
        self.senders.push(sender);
    }

    pub fn len(&self) -> usize {
        return self.senders.len() - self.losers.len();
    }

    pub fn remove(&mut self, i: usize) {
        self.losers.push(i);
    }
}

impl Clone for ChannelSendersList {
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
    fn default() -> Self {
        return ChannelSendersList {
            senders: vec![],
            number: 0,
            losers: vec![]
        }
    }
}