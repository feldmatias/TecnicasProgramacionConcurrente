use std::thread;
use std::time::Duration;

pub mod leader_signal;
use self::leader_signal::LeaderSignal;

pub struct Leader {
    start_signal: LeaderSignal
}

impl Leader {

    pub fn create(signal: LeaderSignal) -> Leader {
        let leader = Leader {
            start_signal: signal
        };

        return leader;
    }

    pub fn start(&self) {
        thread::sleep(Duration::from_secs(1));
        println!("Leader notify miners");
        self.start_signal.signal();
    }
}