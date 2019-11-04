use std::sync::{Arc, Mutex, Condvar};

pub struct LeaderAskPrizeSignal {
    signal: Arc<(Mutex<bool>, Condvar)>,
}

impl LeaderAskPrizeSignal {
    pub fn create() -> LeaderAskPrizeSignal {
        let signal = LeaderAskPrizeSignal {
            signal: Arc::new((Mutex::new(false), Condvar::new()))
        };
        return signal;
    }

    pub fn clone(&self) -> LeaderAskPrizeSignal {
        let signal = LeaderAskPrizeSignal {
            signal: self.signal.clone()
        };
        return signal;
    }

    pub fn wait(&self) {
        let (ref mutex, ref condv) = *self.signal;

        let mut prize_asked = mutex.lock().unwrap();

        while !*prize_asked {
            prize_asked = condv.wait(prize_asked).unwrap();
        }
    }

    pub fn ask_prize(&self) {
        let (ref mutex, ref condv) = *self.signal;

        let mut prize_asked = mutex.lock().unwrap();
        *prize_asked = true;
        condv.notify_all();
    }
}