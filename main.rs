struct BlockObj{
    data: u64,
    id: u32,
    prev: String::from(),
}
fn blockObj_data(self)
{
    return self.data;
}
fn blockObj_prev(self)
{
    return self.prev;
}
fn hash(self)
{
    let add = self.id + self.prev;
    for i in self.data.len()
    {
        a = a + self.data[i];
    }
    return add
}
fn printBlock(self)
{
    println!(self.id);
    println!(self.data);
}

struct Blockchain
{
    blocks: list
}
impl Blockchain
    fn appendBlock(self, &text)
    {
        if self.blocks.len() == 0
            self.blocks.push(BlockObj(text, self.blocks.len(), 0));
        else
            self.blocks.push(BlockObj(text, self.blocks.len(), hash(self.blocks.len()-1]));
    }
    fn getBlock(self, i)
        return self.blocks[i];
    fn size(slef)
        return self.blocks.len()
    fn removeLast(self)
        self.blocks.last().unwrap();
    fn printBlockchain(self)
        for i in self.blocks
            i.printBlock();

fn main()
{
    let myChain = Blockchain();
    myChain.appendBlock("first")
    myChain.appendBlock("second")
    myChain.appendBlock("third")
    myChain.printBlockchain()
}