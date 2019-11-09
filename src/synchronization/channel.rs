use std::sync::mpsc::{Sender, Receiver};
use std::sync::mpsc;
use crate::synchronization::channel::message::Message;

pub mod message;
pub mod channel_senders_list;

pub struct ChannelReceiver {
    receiver: Receiver<Message>,
}

impl ChannelReceiver {
    pub fn receive(&self) -> Message {
        return self.receiver.recv().unwrap();
    }
}

pub struct ChannelSender {
    sender: Sender<Message>,
}

impl ChannelSender {
    pub fn send(&self, msg: Message) {
        self.sender.send(msg).unwrap();
    }
}

impl Clone for ChannelSender {
    fn clone(&self) -> ChannelSender {
        return ChannelSender {
            sender: self.sender.clone()
        };
    }
}

pub fn create_channel() -> (ChannelReceiver, ChannelSender) {
    let (sender, receiver): (Sender<Message>, Receiver<Message>) = mpsc::channel();

    let channel_receiver = ChannelReceiver {
        receiver
    };

    let channel_sender = ChannelSender {
        sender
    };

    return (channel_receiver, channel_sender);
}
