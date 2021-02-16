
#instantiate a block
class BlockObj:
    def __init__(self, data, id, prev):
        self.data = data
        self.id = id
        self.prev = prev

    #Return the data of the block
    def blockObj_data(self):
        return self.data

    #return previos hash
    def blockObj_prev(self):
        return self.prev

    #compute the hash
    def hash(self):
        add = self.id + self.prev
        for i in range(len(self.data)):
            add += int(self.data[i])
        return add

    #print out the contents of the block
    def printBlock(self):
        print(self.id)
        print(self.data)

class Blockchain():
    def __init__(self):
        self.blocks = []

    #Return list of blocks
    def getBlock(self):
        return self.blocks

    #Return number of elements in blockchain
    def size(self):
        return len(self.blocks)

    #Add new block to chain
    def appendBlock(self, text):
        if len(self.blocks) == 0:
            self.blocks.append(BlockObj(text, len(self.blocks), 0))
        else:
            self.blocks.append(BlockObj(text, len(self.blocks), hash( self.blocks[len(self.blocks)-1])))

        # if len(self.blocks) > 1:
        #     if self.blocks[len(self.blocks)] - 1 == hash(self.blocks[len(self.blocks)] - 2):
        #         return len(self.blocks)
        #     else:
        #         return 0
        # else:
        #     return len(self.blocks)

    def removeLast(self):
        del(self.blocks[-1])

    #print out the contents of the blockchain
    def printBlockchain(self):
        for i in self.blocks:
            i.printBlock()


obj = Blockchain()
obj.appendBlock("one")

obj.appendBlock("two")

obj.printBlockchain()
