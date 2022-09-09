#include <stdio.h>
#include <stdlib.h>
#include "rns.h"
#include "node.h"

int main(int argc, char* argv[])
{
    struct commandLineParams cmdParams; 
    parseCommandLine(argc, argv, &cmdParams);
    FILE* fIn = fopen(cmdParams.fileName, "r");
    int numOfNodes = getNumOfNodes(fIn);
    Node nodeList[numOfNodes];
    getNode(nodeList, cmdParams.fileName);
    

    int idx = 0;
    while(idx != numOfNodes)
    {
        printNode(nodeList[idx]);
        idx++;
    }

    return 0; 

}

unsigned int parseCommandLine(int argCount, char* argArray[], struct commandLineParams* z)
{
    int idx = 1;
    // strcpy(z->fileName, DEFAULT_NETWORK_FILE);
    for(; idx < argCount; idx++)
    {
        switch(argArray[idx][1])
        {
            case 'n': 
                strcpy(z->fileName, argArray[idx+1]);
                idx++;
                break;
            
        }
    }
    
    return 0;
}