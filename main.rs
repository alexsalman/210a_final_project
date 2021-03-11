use hello_rust::Block;
use hello_rust::Hashable;

fn main(){
    let mut block = Block::new(0,vec![0; 32]);//hehehe
    //to get the debug one
    println!("{:?}", &block);
    let h = block.hash();
    println!("{:?}", &h);
    block.hash = h;
    println!("{:?}", &block);

    let mut block1 = Block::new(1,vec![0; 32]);//hahaha
    //to get the debug one
    println!("{:?}", &block1);
    let h = block1.hash();
    println!("{:?}", &h);
    block1.hash = h;
    println!("{:?}", &block1);
}