
pub const WINNER : i32 = -10;
pub const LOSER : i32 = -20;
pub const TIE : i32 = -30;
pub const FINAL_RESULT : i32 = -40;

pub struct Message {
    pub miner: usize,
    pub data: i32
}

impl Message {

    pub fn create(sender: usize, data: i32) -> Message {
        return Message { miner: sender, data }
    }
}

impl Copy for Message {}

impl Clone for Message {

    fn clone(&self) -> Self {
        return Message {
            miner: self.miner,
            data: self.data
        }
    }
}