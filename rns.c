#include <stdio.h>
#include <stdlib.h>
#include "rns.h"
#include "node.h"

int main(int args, char* argv[])
{
    FILE* fIn = fopen("basic.ntwk", "r");
    int numOfNodes = getNumOfNodes(fIn);
    struct node nodeList[numOfNodes];
    getNode(nodeList);
    
    
    int idx = 0;
    while(idx != numOfNodes)
    {
        printNode(nodeList[idx]);
        idx++;
    }

    return 0; 

}
