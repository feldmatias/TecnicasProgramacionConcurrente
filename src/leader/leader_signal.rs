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

    pub fn clone(&self) -> LeaderSignal {
        let signal = LeaderSignal {
            signal: self.signal.clone()
        };
        return signal;
    }

    pub fn wait(&self) {
        let (ref mutex, ref condv) = *self.signal;

        let mut started = mutex.lock().unwrap();

        while !*started {
            started = condv.wait(started).unwrap();
        }
    }

    pub fn signal(&self) {
        let (ref mutex, ref condv) = *self.signal;

        let mut started = mutex.lock().unwrap();
        *started = true;
        condv.notify_all();
    }
}