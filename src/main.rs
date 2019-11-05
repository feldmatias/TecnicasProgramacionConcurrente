use std::thread;

pub mod logger;

pub mod miner;
use self::miner::Miner;

pub mod leader;
use self::leader::Leader;
use crate::leader::leader_signal::LeaderSignal;
use crate::leader::leader_channel::create_leader_channel;
use crate::logger::Logger;

fn main() {
    let logger = Logger::create();

    let leader_signal = LeaderSignal::create();
    let (leader_receiver, miner_sender) = create_leader_channel();

    const MINERS : i32 = 10;

    let mut threads = vec![];
    let mut miner_channels = vec![];

    for i in 0..MINERS {

        let leader_signal = leader_signal.clone();
        let sender = miner_sender.clone();

        let (miner_receiver, leader_sender) = create_leader_channel();
        miner_channels.push(leader_sender.clone());

        let t = thread::spawn(move|| {
            let mut miner = Miner {
                leader_signal: leader_signal,
                receiver: miner_receiver,
                sender: sender,
                number: i,
                data: Default::default()
            };
            miner.start();
        });

        threads.push(t);
    }

    let mut leader = Leader {
        leader_signal: leader_signal.clone(),
        receiver: leader_receiver,
        logger: logger,
        miner_channels: miner_channels
    };
    leader.start();


    for thread in threads {
        thread.join().unwrap();
    }

}