use std::sync::{Arc, Condvar, Mutex};
use std::thread;

pub mod miner;
use self::miner::Miner;

pub mod leader;
use self::leader::Leader;

fn main() {
    let condvar = Arc::new((Mutex::new(false), Condvar::new()));

    const MINERS : i32 = 10;

    let mut threads = vec![];

    for i in 0..MINERS {

        let signal = condvar.clone();

        let t = thread::spawn(move|| {
            let miner = Miner::create(&signal, i);
            miner.start();
        });

        threads.push(t);
    }

    let leader = Leader::create(&condvar.clone());
    leader.start();

    println!("Main: waiting to join");
    for thread in threads {
        thread.join().unwrap();
    }

}