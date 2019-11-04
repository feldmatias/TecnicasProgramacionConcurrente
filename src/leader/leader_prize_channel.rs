use std::sync::mpsc::{Sender, Receiver};
use std::sync::mpsc;

pub struct LeaderPrizeReceiver {
    receiver: Receiver<i32>,
}

impl LeaderPrizeReceiver {
    pub fn receive(&self) -> i32 {
        return self.receiver.recv().unwrap();
    }
}

pub struct LeaderPrizeSender {
    sender: Sender<i32>,
}

impl LeaderPrizeSender {
    pub fn clone(&self) -> LeaderPrizeSender {
        return LeaderPrizeSender {
            sender: self.sender.clone()
        };
    }

    pub fn send(&self, prize: i32) {
        return self.sender.send(prize).unwrap();
    }
}

pub fn create_leader_prize_channel() -> (LeaderPrizeReceiver, LeaderPrizeSender) {
    let (sender, receiver): (Sender<i32>, Receiver<i32>) = mpsc::channel();

    let prize_sender = LeaderPrizeSender {
        sender
    };

    let prize_receiver = LeaderPrizeReceiver {
        receiver
    };

    return (prize_receiver, prize_sender);
}
