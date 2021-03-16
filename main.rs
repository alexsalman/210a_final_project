use std::vec::Vec;
use std::string::String;
use chrono::prelude::*;
use std::result::Result;

// instantiate a block
#[derive(Clone, Debug)]
pub struct Block {
    data: String,
    id: i32,
    prev: i32,
}

impl Block {

    pub fn new(prev: i32) -> Self {
        Block {
            data: "".to_string(),
            id: 0,
            prev,
        }
    }

    // print out the contents of the block
    pub fn print_block(self){
        println!("{}", self.id);
        println!("{}", self.data);
    }

}

// instantiate a blockchain
#[derive(Debug, Clone)]
pub struct Blockchain {
    pub blocks: Vec<Block>,
}

impl Blockchain {

    pub fn new() -> Self {
        Blockchain {
            blocks: Vec::new(),
        }
    }

    pub fn get_block(&mut self, i: usize) -> Option<&Block> {
        let res = self.blocks.get(i);
        return res;
    }

    pub fn remove_last(&mut self){
        self.blocks.pop();
    }

    // adds a block to the blockchain
    pub fn append_block(&mut self, _text: String) -> Result<(), String> {
        if self.blocks.len() == 0 {
            self.blocks.push(Block{data: _text, id: self.blocks.len() as i32, prev: 0});
        }
        else{
            // compute the hash
            let hash = self.blocks.len() + self.blocks.len();
            self.blocks.push(Block{data: _text, id: self.blocks.len() as i32, prev: hash as i32});
        }
        Ok(())
    }

    // Will return the number of blocks currently stored
    pub fn len(&self) -> usize {
        self.blocks.len()
    }
 
    pub fn print_block_chain(self){
        for i in self.blocks{
            println!("{:?}", i.print_block());
        }
    }

}

fn main() {

    // current timestamp
    let local: DateTime<Local> = Local::now();
    println!("{}", local);
    
    // Create a new Blockchain
    let mut bc = Blockchain::new();
    
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();
    bc.append_block("test1".to_string());
    bc.len();
    bc.append_block("test".to_string());
    bc.len();

    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);
    bc.get_block(99);

    let to_print = bc.clone();
    to_print.print_block_chain();

    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();
    bc.remove_last();
    bc.len();

    let to_print = bc.clone();
    to_print.print_block_chain();

    // current timestamp
    let local: DateTime<Local> = Local::now();
    println!("{}", local);

}