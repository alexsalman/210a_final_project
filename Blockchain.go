package main

import ("fmt")


type Block struct { 
	data string 
	id  int
	prev float64  
}

type BlockFuctions interface {
    getData() string
	previosHash() float64
	hash() float64
	printBlock() 
	newBlock() Block
	
}

func (b Block) getData() string {
    return b.data
}

func (b Block) previosHash() float64 {
    return b.prev
}


func (b Block) hash() float64 {
	var total = float64(b.id) + b.prev

   for i := 0; i < len(b.data); i++ {
	   total=total+float64(b.data[i])
	} 

	return total
}

func (b Block) printBlock() {

	fmt.Print(b.id)
	fmt.Print(b.data)
}


	






type Blockchain struct { 
	count int
    chain []Block
}


type BlockchainFuctions interface {
	get() Block
	size() int
	appendBlock()
	removeLast()
	printBlockchain()

	
}

func (B Blockchain) get(id int) Block {
	return (B.chain[id])
}



func (B Blockchain) size() int {
	return (B.count)
}



func (B Blockchain) appendBlock(data string) {


	if(B.count==0){

		// fmt.Print("here")

		var tempBlock = Block{data, B.count, 0}


		B.chain=append(B.chain, tempBlock)

		fmt.Print(B.chain)
	}else{

		var tempBlock = Block{data, B.count, B.chain[(B.count)-1].hash()}
		B.chain=append(B.chain, tempBlock)

	}

	
	B.count=B.count+1
	
}



func (B Blockchain) removeLast() {
	if B.count==0 {
		return
	}else {
		B.chain = B.chain[:len(B.chain)-1] 
		B.count=B.count-1
	}
		
}


func (B Blockchain) printBlockchain() {
	fmt.Print("here")
	for i := 0; i < B.count; i++ {
		// fmt.Print(i)
	// for i := range (B.count){
		B.chain[i].printBlock()
		
	}
}


func main(){
	var myChain=Blockchain{}
	
	myChain.appendBlock("one")
	fmt.Print(myChain.count)
	
	myChain.printBlockchain()
}


