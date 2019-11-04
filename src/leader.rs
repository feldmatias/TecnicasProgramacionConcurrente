use std::thread;
use std::time::Duration;

pub mod leader_signal;
use self::leader_signal::LeaderSignal;

pub struct Leader {
    leader_signal: LeaderSignal
}

impl Leader {

    pub fn create(signal: LeaderSignal) -> Leader {
        let leader = Leader {
            leader_signal: signal
        };

        return leader;
    }

    pub fn start(&self) {
        thread::sleep(Duration::from_secs(1));

        self.start_mining()
    }

    fn start_mining(&self) {
        self.leader_signal.signal_start();

        thread::sleep(Duration::from_secs(2));

        self.leader_signal.signal_end()
    }
}