use std::thread;
use std::time::Duration;

use rand::Rng;

/**
 * Class to simulate time.
 */
pub struct TimeSimulator {}

impl TimeSimulator {
    /**
     * Simulate time wait between from and to milliseconds
     */
    pub fn simulate_time_between(from: u64, to: u64) {
        thread::sleep(Duration::from_millis(rand::thread_rng().gen_range(from, to)));
    }
}