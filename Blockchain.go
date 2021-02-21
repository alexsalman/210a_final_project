
import ( 
    "fmt"
) 


type Block struct { 
	data string 
	id  int
	prev float64  
}

type BlockFuctions interface {
    data() string
	previosHash() float64
	hash() float64
	printBlock() 
	newBlock() Block
	
}

func (b Block) data() string {
    return b.data
}

func (b Block) previosHash() float64 {
    return b.prev
}


func (b Block) hash() float64 {
	var total = b.id + b.prev

   for i := 0; i < len(b.data); i++ {
	   total=total+int(b.data[i)])
	} 


}

func (b Block) printBlock() {

	fmt.Print(b.id)
	fmt.Print(b.data)
}


	






type Blockchain struct { 
	count int
    var chain [100]Block
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

		var tempBlock = Block{data, B.count, 0}

		// B.chain=append(B.chain, tempBlock)
	}
	else{

		var tempBlock = Block{data, B.count, hash(B.chain[(B.count)-1])}

	}

	B.chain=append(B.chain, tempBlock)
	B.count=B.count+1
	
}



func (B Blockchain) removeLast() {
	if(B.count==0){
		return
	}
	else{
		B.chain = B.chain[:len(B.chain)-1] 
		B.count=B.count-1
	}
		
}


func (B Blockchain) printBlockchain() {
	for i in range(B.chain){
		printBlock(i)
	}
}


func main(){
	var myChain=Blockchain{}
	
	myChain.appendBlock("one")
	
	myChain.printBlockchain()
}


