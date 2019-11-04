use std::thread;

pub mod miner;
use self::miner::Miner;

pub mod leader;
use self::leader::Leader;
use crate::leader::leader_signal::LeaderSignal;

fn main() {
    let leader_signal = LeaderSignal::create();

    const MINERS : i32 = 10;

    let mut threads = vec![];

    for i in 0..MINERS {

        let signal = leader_signal.clone();

        let t = thread::spawn(move|| {
            let miner = Miner::create(signal, i);
            miner.start();
        });

        threads.push(t);
    }

    let leader = Leader::create(leader_signal.clone());
    leader.start();

    println!("Main: waiting to join");
    for thread in threads {
        thread.join().unwrap();
    }

}