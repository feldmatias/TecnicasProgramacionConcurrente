use std::sync::{Arc, Condvar, Mutex};

/**
 * Class that simulates a barrier.
 */
pub struct Barrier {
    barrier: Arc<(Mutex<usize>, Condvar)>,
    last_value: usize,
}

impl Barrier {
    /**
     * Create a new barrier.
     */
    pub fn create() -> Barrier {
        let barrier = Barrier {
            barrier: Arc::new((Mutex::new(0), Condvar::new())),
            last_value: 0,
        };
        return barrier;
    }

    /**
     * Wait until all <participants> are synchronized.
     */
    pub fn wait(&mut self, participants: usize) {
        let (ref mutex, ref condv) = *self.barrier;

        let mut current = mutex.lock().unwrap();
        *current += 1;


        if *current >= participants + self.last_value {
            condv.notify_all();
        }

        while *current < participants + self.last_value {
            current = condv.wait(current).unwrap();
        }

        self.last_value += participants;
    }
}

impl Clone for Barrier {
    /**
     * Clone the barrier.
     */
    fn clone(&self) -> Barrier {
        let barrier = Barrier {
            barrier: self.barrier.clone(),
            last_value: self.last_value,
        };
        return barrier;
    }
}