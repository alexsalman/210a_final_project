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
void printBlock(FILE *out, Block B)
{
    fprintf(out, " %d ", B->id);
    for (int i = 0; i < strlen(B->data); i++)
    {
        fprintf(out, "%c", B->data[i]);
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
    int max;
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
    return B->max;
}

//Add new block to chain
int append(Blockchain B, char *data)
{
    if (valid(B) != 1)
    {
        return 0;
    }

    if (B->max == 0)
    {

        B->list[0] = newBlock(data, (B->max), 0);
    }
    else
    {

        B->list[B->max] = newBlock(data, (B->max), hash(B->list[(B->max) - 1]));
    }

    B->max++;

    if ((B->max) > 1)
    {

        if (previousHash(B->list[(B->max) - 1]) == hash(B->list[(B->max) - 2]))
        {
            return B->max;
        }
        else
        {
            return 0;
        }
    }
    else
    {

        return B->max;
    }
}

//check if the blockchain is valid ie. verify every block in the chain in storing the correct previos hash
int valid(Blockchain B)
{
    int valid = -1;

    if (B->max <= 1)
    {
        return 1;
    }

    for (int i = 1; i < B->max; i++)
    {

        if (previousHash(B->list[i]) == hash(B->list[(i)-1]))
        {
            //		if(B[i]->prev < B[i+1]->prev){
            valid = 1;
        }
        else
        {
            valid = 0;
            return valid;
        }
    }
    return valid;
}

//remove last block of the blockchain
void removeLast(Blockchain B)
{
    if (B->max == 0)
    {
        return;
    }
    else
    {
        freeBlock(&B->list[B->max]);
        B->max--;
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
    b->max = 0;
    return b;
}

//print out the contents of the blockchain
void printBlockchain(FILE *out, Blockchain B)
{
    for (int i = 0; i < (B->max); i++)
    {
        printBlock(out, B->list[i]);
    }
}




// MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN

//test functions above
int main(int argc, char *argv[])
{
    Blockchain chain = newBlockchain();
    char hackable[] = "one";
    printf("%d\n", append(chain, hackable));
    printf("%d\n", append(chain, "two"));
    printf("%d\n", append(chain, "three"));
    printf("valid = %d\n", valid(chain));
    for (int i = 0; i < size(chain); i++)
    {
        printBlock(stdout, get(chain, i));
    }
    removeLast(chain);
    printBlockchain(stdout, chain);

    Block b = get(chain, 0);
    char *value = data(b);
    *value = (*value) + 1; // change a value in the first block
    printf("valid = %d\n", valid(chain));

    printf("%d\n", append(chain, "five"));
    freeBlockchain(&chain);
    return 0;
}