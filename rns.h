#ifndef RNS_HEADER
#define RNS_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

#define NO_CMD_LINE 8
#define CMD_LINE_ERR 9
#define DEFAULT_NETWORK_FILE "basic.ntwk"
#define MAX_CHAR 256
#define BUFFER_SIZE 1024

enum networkState{nodeState};


struct commandLineParams
{
    char fileName[MAX_CHAR];
};


int getNumOfNodes(FILE* x)
{
    char buffer[BUFFER_SIZE];
    int num = 0;
    while(!feof(x))
    {
    	fgets(buffer, BUFFER_SIZE, x);
    	if(strncmp(buffer, "endNode", strlen("endNode")) == 0)
        {
            num++;
        }    
    }
    fclose(x);

    return num;   
}

unsigned int parseCommandLine(int argCount, char* argArray[], struct commandLineParams* z);

#endif
