use std::sync::{Arc, Mutex, Condvar};

pub struct LeaderSignal {
    signal: Arc<(Mutex<bool>, Condvar)>,
}

impl LeaderSignal {
    pub fn create() -> LeaderSignal {
        let signal = LeaderSignal {
            signal: Arc::new((Mutex::new(false), Condvar::new()))
        };
        return signal;
    }

    pub fn wait(&self) {
        let (ref mutex, ref condv) = *self.signal;

        let mut start = mutex.lock().unwrap();

        while !*start {
            start = condv.wait(start).unwrap();
        }
    }

    pub fn signal_start(&self) {
        let (ref mutex, ref condv) = *self.signal;

        let mut started = mutex.lock().unwrap();
        *started = true;
        condv.notify_all();
    }

    pub fn signal_end(&self) {
        let (ref mutex, _) = *self.signal;

        let mut mining = mutex.lock().unwrap();
        *mining = false;
    }

    pub fn should_continue(&self) -> bool {
        let (ref mutex, _) = *self.signal;

        let mining = mutex.lock().unwrap();
        return *mining
    }
}

impl Clone for LeaderSignal {
    fn clone(&self) -> LeaderSignal {
        let signal = LeaderSignal {
            signal: self.signal.clone()
        };
        return signal;
    }
}