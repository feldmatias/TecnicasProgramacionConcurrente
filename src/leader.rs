use std::thread;
use std::sync::{Arc, Mutex, Condvar};
use std::time::Duration;

pub mod leader_signal;
use self::leader_signal::LeaderSignal;

pub struct Leader {
    start_signal: LeaderSignal
}

impl Leader {

    pub fn create(signal: &Arc<(Mutex<bool>, Condvar)>) -> Leader {
        let leader = Leader {
            start_signal: LeaderSignal::create(signal)
        };

        return leader;
    }

    pub fn start(&self) {
        thread::sleep(Duration::from_secs(1));
        println!("Leader notify miners");
        self.start_signal.signal();
    }
}