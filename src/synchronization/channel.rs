use std::sync::mpsc::{Receiver, Sender};
use std::sync::mpsc;

use crate::synchronization::channel::message::Message;

pub mod message;
pub mod channel_senders_list;

/**
 * Receiver end of a channel.
 */
pub struct ChannelReceiver {
    receiver: Receiver<Message>,
}

impl ChannelReceiver {
    /**
     * Receive new message.
     */
    pub fn receive(&self) -> Message {
        return self.receiver.recv().unwrap();
    }
}

/**
 * Sender end of a channel.
 */
pub struct ChannelSender {
    sender: Sender<Message>,
}

impl ChannelSender {
    /**
     * Send a new message.
     */
    pub fn send(&self, msg: Message) {
        self.sender.send(msg).unwrap();
    }
}

impl Clone for ChannelSender {
    /**
     * Clone the sender.
     */
    fn clone(&self) -> ChannelSender {
        return ChannelSender {
            sender: self.sender.clone()
        };
    }
}

/**
 * Create a channel with a sender and a receiver.
 */
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
