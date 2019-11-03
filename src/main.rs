use std::sync::{Arc, Condvar, Mutex};
use std::thread;
use std::time::Duration;

fn main() {
    let condvar = Arc::new((Mutex::new(false), Condvar::new()));

    const MINERS : i32 = 5;

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

// of course this goes to another file
struct Miner {
    start_signal: LeaderSignal,
    number: i32
}

impl Miner {
    fn create(signal: &Arc<(Mutex<bool>, Condvar)>, i : i32) -> Miner {
        let signal = LeaderSignal {
            signal: signal.clone()
        };

        let miner = Miner {
            start_signal: signal,
            number: i
        };

        return miner;
    }

    fn start(&self) {
        self.start_signal.wait();

        thread::sleep(Duration::from_millis(100));
        println!("Miner {} started and did work", self.number);
    }
}

// of course this goes to another file
struct Leader {
    start_signal: LeaderSignal
}

impl Leader {

    fn create(signal: &Arc<(Mutex<bool>, Condvar)>) -> Leader {
        let signal = LeaderSignal {
            signal: signal.clone()
        };

        let leader = Leader {
            start_signal: signal
        };

        return leader;
    }

    fn start(&self) {
        thread::sleep(Duration::from_secs(1));
        println!("Leader notify miners");
        self.start_signal.signal();
    }
}

// of course this goes to another file
struct LeaderSignal {
    signal: Arc<(Mutex<bool>, Condvar)>,
}

impl LeaderSignal {
    fn wait(&self) {
        let (ref mutex, ref condv) = *self.signal;

        let mut started = mutex.lock().unwrap();

        while !*started {
            started = condv.wait(started).unwrap();
        }
    }

    fn signal(&self) {
        let (ref mutex, ref condv) = *self.signal;

        let mut started = mutex.lock().unwrap();
        *started = true;
        condv.notify_all();
    }
}