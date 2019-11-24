use std::thread;

use crate::config::Config;
use crate::leader::LEADER_NUMBER;
use crate::logger::Logger;
use crate::mines_map::MinesMap;
use crate::synchronization::SyncInfo;

use self::leader::Leader;
use self::miner::Miner;

pub mod logger;

pub mod miner;

pub mod leader;

pub mod synchronization;
pub mod config;
pub mod mines_map;

/**
 * Main function. Thread and sync resources initialization.
 */
fn main() {
    let config = Config::get();

    let logger = Logger::create();
    let mut sync = SyncInfo::initialize(&config);
    let mines_map = MinesMap::create();

    let mut threads = vec![];


    let mut leader = Leader::create(sync.data_for(LEADER_NUMBER), mines_map.clone(), logger.clone());


    for i in 1..config.miners + 1 {
        // Initialize miners
        let sync = (&mut sync).data_for(i);
        let logger = logger.clone();
        let mines_map = mines_map.clone();

        let t = thread::spawn(move || {
            let mut miner = Miner::create(sync, i as usize, mines_map, logger);
            miner.start();
        });

        threads.push(t);
    }

    leader.start();


    for thread in threads {
        thread.join().unwrap();
    }
}