#ifndef RNS_HEADER
#define RNS_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

enum networkState{nodeState};

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


#endif