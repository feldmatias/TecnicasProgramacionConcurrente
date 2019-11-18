pub const WINNER: i32 = -10;
pub const LOSER: i32 = -20;
pub const TIE: i32 = -30;
pub const FINAL_RESULT: i32 = -40;

/**
 * Message to send through channels.
 */
pub struct Message {
    pub miner: usize,
    pub data: i32,
}

impl Message {
    /**
     * Create a message.
     */
    pub fn create(sender: usize, data: i32) -> Message {
        return Message { miner: sender, data };
    }
}

impl Copy for Message {}

impl Clone for Message {
    /**
     * Clone the message.
     */
    fn clone(&self) -> Self {
        return Message {
            miner: self.miner,
            data: self.data,
        };
    }
}