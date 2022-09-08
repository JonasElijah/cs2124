#ifndef RNS_HEADER
#define RNS_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

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
    char connection[BUFFER_SIZE];
    int num = 0;
    while(!feof(x))
    {
    	fgets(buffer, BUFFER_SIZE, x);
        // if(strcmp(buffer, connection) == 0)
        // {
        //     return badFormat;
        // }

    	if(strncmp(buffer, "endNode", strlen("endNode")) == 0)
        {
            num++;
        }
        
        // if(buffer[0] != '#' && strchr(buffer,',') == 0 && strcmp(buffer, "endNode\r\n") == 0 && strcmp(buffer, "endNet\r\n") == 0)
        // {
        //    strset(connection, buffer);
        // }
         
    }
    fclose(x);

    return num;   
}

unsigned int parseCommandLine(int argCount, char* argArray[], struct commandLineParams* z);

#endif