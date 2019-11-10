pub struct MinerData {
    pub current_mines : usize,
    pub total_mined: usize,
    pub total_earned: usize
}

impl Default for MinerData {
    fn default() -> Self {
        return MinerData {
            current_mines: 0,
            total_mined: 0,
            total_earned: 0
        }
    }
}

impl MinerData {

    pub(crate) fn set_total(&mut self) {
        self.total_mined += self.current_mines;
        self.current_mines = 0;
    }

    pub fn add_earned(&mut self, earned: usize) {
        self.total_earned += earned;
    }
}