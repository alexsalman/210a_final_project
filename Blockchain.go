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