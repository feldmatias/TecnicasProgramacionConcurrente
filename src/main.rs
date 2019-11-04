use std::thread;

pub mod miner;
use self::miner::Miner;

pub mod leader;
use self::leader::Leader;
use crate::leader::leader_signal::LeaderSignal;
use crate::leader::leader_ask_prize_signal::LeaderAskPrizeSignal;
use crate::leader::leader_prize_channel::create_leader_prize_channel;

fn main() {
    let leader_signal = LeaderSignal::create();
    let (leader_prize_receiver, miner_prize_sender) = create_leader_prize_channel();

    const MINERS : i32 = 10;

    let mut threads = vec![];
    let mut ask_prize_signals = vec![];

    for i in 0..MINERS {

        let leader_signal = leader_signal.clone();
        let prize_sender = miner_prize_sender.clone();

        let ask_prize_signal = LeaderAskPrizeSignal::create();
        ask_prize_signals.push(ask_prize_signal.clone());

        let t = thread::spawn(move|| {
            let mut miner = Miner {
                leader_signal: leader_signal,
                leader_ask_prize_signal: ask_prize_signal,
                prize_sender: prize_sender,
                number: i,
                data: Default::default()
            };
            miner.start();
        });

        threads.push(t);
    }

    let leader = Leader {
        leader_signal: leader_signal.clone(),
        prize_receiver: leader_prize_receiver
    };
    leader.start(ask_prize_signals);


    println!("Main: waiting to join");
    for thread in threads {
        thread.join().unwrap();
    }

}