use std::sync::mpsc::{Sender, Receiver};
use std::sync::mpsc;

const CHANNEL_SIGNAL : i32 = -1;

pub struct ChannelReceiver {
    receiver: Receiver<i32>,
}

impl ChannelReceiver {
    pub fn receive(&self) -> i32 {
        return self.receiver.recv().unwrap();
    }

    pub fn receive_signal(&self) {
        self.receive();
    }
}

pub struct ChannelSender {
    sender: Sender<i32>,
}

impl ChannelSender {
    pub fn send(&self, data: i32) {
        self.sender.send(data).unwrap();
    }

    pub fn send_signal(&self) {
        self.send(CHANNEL_SIGNAL);
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
