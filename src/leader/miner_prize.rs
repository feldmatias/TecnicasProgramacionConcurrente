pub const MINER_EQUAL_PRIZES : i32 = -1;

pub struct MinerPrize {
    pub miner_number : i32,
    pub miner_prize : i32
}

impl Copy for MinerPrize {}

impl Clone for MinerPrize {
    fn clone(&self) -> Self {
        return MinerPrize {
            miner_number: self.miner_number,
            miner_prize: self.miner_prize
        }
    }
}

impl Default for MinerPrize {
    fn default() -> Self {
        return MinerPrize {
            miner_number: MINER_EQUAL_PRIZES,
            miner_prize: std::i32::MAX
        };
    }
}