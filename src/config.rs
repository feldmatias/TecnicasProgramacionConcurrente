use clap::{App, Arg};

const DEFAULT_MINERS : &str = "10";
const DEFAULT_ROUNDS : &str = "10";

/**
 * Class that holds config values.
 */
pub struct Config {
    pub miners: usize,
    pub rounds: usize
}

impl Config {

    /**
     * Get config from command line arguments.
     */
    pub fn get() -> Config {
        let matches = App::new("Concu-Mining")
            .version("1.0")
            .arg(Arg::with_name("miners")
                .short("m")
                .long("miners")
                .value_name("miners")
                .help("Amount of miners")
                .default_value(DEFAULT_MINERS)
                .takes_value(true))
            .arg(Arg::with_name("rounds")
                .short("r")
                .long("rounds")
                .value_name("rounds")
                .help("Amount of rounds")
                .default_value(DEFAULT_ROUNDS)
                .takes_value(true))
            .get_matches();

        return Config {
            miners: matches.value_of("miners").unwrap().parse().unwrap(),
            rounds: matches.value_of("rounds").unwrap().parse().unwrap()
        }
    }
}

