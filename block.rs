
use std::fmt::{self, Debug, Formatter };
use super::*;

pub struct Block{
    pub index: u32,
    pub hash: BlockHash,
    pub prev_block_hash: BlockHash,
}

impl Debug for Block{
    fn fmt (&self, f: &mut Formatter) -> fmt::Result {
        write!(f, "Block[{}]: {}",
            &self.index,
            &hex::encode(&self.hash),
        )
    }
}

impl Block {
    pub fn new(
        index: u32,
        prev_block_hash: BlockHash,
    ) -> Self{
        Block {
            index,
            hash: vec![0; 32],
            prev_block_hash,
        }
    }
}

impl Hashable for Block{
    fn bytes (&self) -> Vec<u8> {
        let mut bytes = vec![];

        bytes.extend(&u32_bytes(&self.index));
        bytes.extend(&self.prev_block_hash);

        bytes
    }
}
