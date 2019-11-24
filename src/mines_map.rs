use std::sync::{Arc, Mutex};
use std::fs::File;
use std::io::{BufReader, BufRead};

const MINES_MAP_CONFIG : &str = "mines_map.txt";

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
            current: Arc::new(Mutex::new(0))
        }
    }
}

impl Clone for MinesMap {
    /**
     * Clone the map.
     */
    fn clone(&self) -> Self {
        return MinesMap {
            map: self.map.clone(),
            current: self.current.clone(),
        }
    }
}