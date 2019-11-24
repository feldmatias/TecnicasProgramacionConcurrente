use std::fs::File;
use std::io::{BufRead, BufReader};
use std::sync::{Arc, Mutex};

const MINES_MAP_CONFIG: &str = "mines_map.txt";

pub struct MinesMap {
    pub map: Arc<Vec<usize>>,
    current: Arc<Mutex<usize>>,
}

impl MinesMap {
    /**
     * Create the map.
     */
    pub fn create() -> MinesMap {
        let file = File::open(MINES_MAP_CONFIG).unwrap();
        let reader = BufReader::new(file);

        let mut map = vec![];

        for line in reader.lines() {
            map.push(line.unwrap().parse::<usize>().unwrap());
        }

        return MinesMap {
            map: Arc::new(map),
            current: Arc::new(Mutex::new(0)),
        };
    }

    /**
    * Start a new round.
    */
    pub fn start_round(&self, round_number: usize) -> usize {
        let mut current = self.current.lock().unwrap();
        let map = round_number % self.map.len();
        *current = self.map[map];
        return *current;
    }

    /**
    * Get a mine if available.
    */
    pub fn get_mine(&self) -> usize {
        let mut current = self.current.lock().unwrap();
        if *current == 0 {
            return 0;
        }

        *current -= 1;
        return 1;
    }

    /**
    * Get current amount of mines.
    */
    pub fn get_current(&self) -> usize {
        let current = self.current.lock().unwrap();
        return *current;
    }
}

impl Clone for MinesMap {
    /**
     * Clone the map.
     */
    fn clone(&self) -> Self {
        return MinesMap {
            map: Arc::clone(&self.map),
            current: Arc::clone(&self.current),
        };
    }
}