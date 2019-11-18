use std::fs::File;
use std::io::Write;
use std::sync::{Arc, Mutex};

const LOG_FILE: &str = "log.txt";

/**
 * Class to log debug data.
 */
pub struct Logger {
    mutex: Arc<Mutex<i32>>,
    file: File,
}

impl Logger {
    /**
     * Create the logger.
     */
    pub fn create() -> Logger {
        let file = File::create(LOG_FILE).unwrap();
        let mutex = Arc::new(Mutex::new(0));

        return Logger {
            mutex,
            file,
        };
    }

    /**
     * Write a line in the log.
     */
    pub fn log(&mut self, line: String) {
        let _ = self.mutex.lock().unwrap();
        println!("{}", line);
        self.file.write_all(format!("{}\n", line).as_ref()).unwrap();
    }
}

impl Clone for Logger {
    /**
     * Clone the logger.
     */
    fn clone(&self) -> Logger {
        return Logger {
            mutex: self.mutex.clone(),
            file: self.file.try_clone().unwrap(),
        };
    }
}