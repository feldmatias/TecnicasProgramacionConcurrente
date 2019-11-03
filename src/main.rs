use std::sync::{Arc, Condvar, Mutex};
use std::thread;
use std::time::Duration;

fn main() {
    let condvar = Arc::new((Mutex::new(false), Condvar::new()));

    const MINERS : i32 = 5;

    let mut threads = vec![];

    for i in 0..MINERS {

        let clone = condvar.clone();

        let t = thread::spawn(move|| {
            let (mutex, condv) = &*clone;

            let started = mutex.lock().unwrap();
            condv.wait(started).unwrap();

            println!("Thread {} started", i);
        });

        threads.push(t);
    }

    thread::sleep(Duration::from_secs(1));
    println!("Main notify threads");

    let (_lock, cvar) = &*condvar;
    cvar.notify_all();

    for thread in threads {
        thread.join().unwrap();
    }

}
