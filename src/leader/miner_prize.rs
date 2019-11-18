pub const NO_MINER: i32 = -1;

/**
 * Class to store miners prize.
 */
pub struct MinerPrize {
    pub miner_number: i32,
    pub miner_prize: i32,
}

impl MinerPrize {
    /**
     * Calculate the loser based on prizes list.
     */
    pub fn get_loser(prizes: &Vec<MinerPrize>) -> MinerPrize {
        let mut min = MinerPrize::default();

        for prize in prizes {
            if prize.miner_prize < min.miner_prize {
                min = *prize;
            } else if prize.miner_prize == min.miner_prize {
                min.miner_number = NO_MINER;
            }
        }

        return min;
    }

    /**
     * Calculate the winners based on prizes list.
     */
    pub fn get_winners(prizes: &Vec<MinerPrize>) -> Vec<i32> {
        let mut winners = vec![];
        let mut max = -1;

        for prize in prizes {
            if prize.miner_prize > max {
                max = prize.miner_prize;
                winners.clear();
                winners.push(prize.miner_number);
            } else if prize.miner_prize == max {
                winners.push(prize.miner_number);
            }
        }

        return winners;
    }
}


impl Copy for MinerPrize {}

impl Clone for MinerPrize {
    /**
     * Clone the prize.
     */
    fn clone(&self) -> Self {
        return MinerPrize {
            miner_number: self.miner_number,
            miner_prize: self.miner_prize,
        };
    }
}

impl Default for MinerPrize {
    /**
     * Create an empty prize.
     */
    fn default() -> Self {
        return MinerPrize {
            miner_number: NO_MINER,
            miner_prize: std::i32::MAX,
        };
    }
}
