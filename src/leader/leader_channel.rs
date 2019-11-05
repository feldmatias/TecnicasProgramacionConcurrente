use std::sync::mpsc::{Sender, Receiver};
use std::sync::mpsc;

pub struct ChannelReceiver {
    receiver: Receiver<i32>,
}

impl ChannelReceiver {
    pub fn receive(&self) -> i32 {
        return self.receiver.recv().unwrap();
    }
}

pub struct ChannelSender {
    sender: Sender<i32>,
}

impl ChannelSender {
    pub fn send(&self, data: i32) {
        return self.sender.send(data).unwrap();
    }
}

impl Clone for ChannelSender {
    fn clone(&self) -> ChannelSender {
        return ChannelSender {
            sender: self.sender.clone()
        };
    }
}

pub fn create_leader_channel() -> (ChannelReceiver, ChannelSender) {
    let (sender, receiver): (Sender<i32>, Receiver<i32>) = mpsc::channel();

    let prize_sender = ChannelSender {
        sender
    };

    let prize_receiver = ChannelReceiver {
        receiver
    };

    return (prize_receiver, prize_sender);
}
