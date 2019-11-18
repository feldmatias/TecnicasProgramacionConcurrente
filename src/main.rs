use std::thread;

pub mod logger;
use crate::logger::Logger;

pub mod miner;
use self::miner::Miner;

pub mod leader;
use self::leader::Leader;
use crate::synchronization::SyncInfo;
use crate::leader::LEADER_NUMBER;
use crate::config::Config;

pub mod synchronization;
pub mod config;

/**
 * Main function. Thread and sync resources initialization.
 */
fn main() {
    let config = Config::get();

    let logger = Logger::create();
    let mut sync = SyncInfo::initialize(&config);

    let mut threads = vec![];


    let mut leader = Leader::create(sync.data_for(LEADER_NUMBER), logger.clone());


    for i in 1..config.miners + 1 {
        // Initialize miners
        let sync = (&mut sync).data_for(i);
        let logger_clone = logger.clone();

        let t = thread::spawn( move||{
            let mut miner = Miner::create(sync, i as usize, logger_clone);
            miner.start();
        });

        threads.push(t);
    }

    leader.start();


    for thread in threads {
        thread.join().unwrap();
    }

}