#ifndef RNS_HEADER
#define RNS_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define BUFFER_SIZE 1024

enum networkState{nodeState};


struct commandLineParams
{
    char fileName[MAX_CHAR];
};


int getNumOfNodes(FILE* x)
{
    int num = 0;
    while(!feof(x))
    {
    	char buffer[BUFFER_SIZE];
    	fgets(buffer, BUFFER_SIZE, x);
    	if(strcmp(buffer, "endNode\r\n") == 0)
        {
            num++;
        }
         
    }
    fclose(x);

    return num;   
}

unsigned int parseCommandLine(int argCount, char* argArray[], struct commandLineParams* z);

#endif