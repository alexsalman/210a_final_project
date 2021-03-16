///This implementation of blockchain is modeled after code written for another class.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//instantiate a block 
typedef struct BlockObj
{
    char *data;
    int id;
    long prev;
} BlockObj;

typedef struct BlockObj *Block;


//Return the data of the block
char *data(Block B)
{
    return B->data;
}

//return previos hash
long previousHash(Block B)
{
    return B->prev;
}

//compute the hash
long hash(Block B)
{
    long add;

    add = (long)(B->id) + (B->prev);
    for (int i = 0; i < strlen(B->data); i++)
    {
        add = add + (long)B->data[i];   
    }
    return add;
}

//print out the contents of the block
void printBlock(Block B)
{
    fprintf(stdout, " %d ", B->id);
    for (int i = 0; i < strlen(B->data); i++)
    {
        fprintf(stdout, "%c", B->data[i]);
    }
}

//Constuctor to create new block
Block newBlock(char *data, int id, long hash)
{

    Block b = malloc(sizeof(BlockObj));
    if (id == 0)
    {
        hash = 0;
    }
    assert(b != NULL);
    b->data = data;
    b->id = id;
    b->prev = hash;
    return b;
}

//Free up allocated memory of block 
void freeBlock(Block *pB)
{
    if (pB != NULL && *pB != NULL)
    {
        free(*pB);
        *pB = NULL;
    }
}



//BLOCKCHAIN BLOCKCHAIN BLOCKCHAIN BLOCKCHAIN BLOCKCHAIN



//Defintion Blockchain
typedef struct BlockchainObj
{
    int count;
    Block list[100];
} BlockchainObj;

typedef struct BlockchainObj *Blockchain;


//Return list of blocks
Block get(Blockchain B, int idx)
{

    return B->list[idx];
}

//Return number of ellements in blockchain
int size(Blockchain B)
{
    return B->count;
}

//Add new block to chain
int append(Blockchain B, char *data)
{
    
    if (B->count == 0)
    {

        B->list[0] = newBlock(data, (B->count), 0);
    }
    else
    {

        B->list[B->count] = newBlock(data, (B->count), hash(B->list[(B->count) - 1]));
    }

    B->count++;

    if ((B->count) > 1)
    {

        if (previousHash(B->list[(B->count) - 1]) == hash(B->list[(B->count) - 2]))
        {
            return B->count;
        }
        else
        {
            return 0;
        }
    }
    else
    {

        return B->count;
    }
}


//remove last block of the blockchain
void removeLast(Blockchain B)
{
    if (B->count == 0)
    {
        return;
    }
    else
    {
        freeBlock(&B->list[B->count]);
        B->count--;
    }
}

//free the memory allocated for the blockchain
void freeBlockchain(Blockchain *pB)
{
    pB[0] = '\0';
    free(*pB);
    *pB = NULL;
}

//Constructor for a new blockchain object
Blockchain newBlockchain()
{
    Blockchain b = malloc(sizeof(BlockchainObj));
    b->count = 0;
    return b;
}

//print out the contents of the blockchain
void printBlockchain(Blockchain B)
{
    for (int i = 0; i < (B->count); i++)
    {
        printBlock( B->list[i]);
    }
}




// MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN

//test functions above
int main(int argc, char *argv[])
{
    Blockchain myChain = newBlockchain();
    
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    append(myChain, "test");
    size(myChain);
    
    
    
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
    get(myChain,99);
   
    
    // printf("%d\n", append(myChain, "one"));
    // printf("%d\n", append(myChain, "two"));

    // char myData[] = "three";

    // printf("%d\n", append(myChain, myData));
   
    printBlockchain(myChain);

    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    removeLast(myChain);
    size(myChain);
    
    
    printBlockchain(myChain);

    // Block b = get(myChain, 1);
    // char *value = data(b);
    // *value = (*value) + 1; // change a value in the first block

    freeBlockchain(&myChain);
    return 0;
}
