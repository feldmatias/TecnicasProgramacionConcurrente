use std::sync::{Arc, Condvar, Mutex};

/**
 * Class that allows the leader top send start and stop signals to miners.
 */
pub struct LeaderSignal {
    signal: Arc<(Mutex<bool>, Condvar)>,
}

impl LeaderSignal {
    /**
     * Create the signal.
     */
    pub fn create() -> LeaderSignal {
        let signal = LeaderSignal {
            signal: Arc::new((Mutex::new(false), Condvar::new()))
        };
        return signal;
    }

    /**
     * Wait for the start signal.
     */
    pub fn wait(&self) {
        let (ref mutex, ref condv) = *self.signal;

        let mut start = mutex.lock().unwrap();

        while !*start {
            start = condv.wait(start).unwrap();
        }
    }

    /**
     * Send a signal to start.
     */
    pub fn signal_start(&self) {
        let (ref mutex, ref condv) = *self.signal;

        let mut started = mutex.lock().unwrap();
        *started = true;
        condv.notify_all();
    }

    /**
     * Send the signal to end.
     */
    pub fn signal_end(&self) {
        let (ref mutex, _) = *self.signal;

        let mut mining = mutex.lock().unwrap();
        *mining = false;
    }

    /**
     * If end signal is not received yet.
     */
    pub fn should_continue(&self) -> bool {
        let (ref mutex, _) = *self.signal;

        let mining = mutex.lock().unwrap();
        return *mining;
    }
}

impl Clone for LeaderSignal {
    /**
     * Clone the signal.
     */
    fn clone(&self) -> LeaderSignal {
        let signal = LeaderSignal {
            signal: self.signal.clone()
        };
        return signal;
    }
}