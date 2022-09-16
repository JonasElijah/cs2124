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
#define MIN_COMMAND_LINE_ARGUMENTS 3

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

int formatCheck(char* x)
{
	FILE* fIn = fopen(x, "r");
	if((fIn == NULL))
        {
    	    return emptyFile;
        }
	char buffer[BUFFER_SIZE];
	int nodeIDCount = 0, connCounter = 0, listConnCount = 0, counter = 0;
	while(!feof(fIn))
	{
		fgets(buffer, BUFFER_SIZE, fIn);
		if(buffer[0] == '#')
		{
			continue;
		}

		if(strncmp(buffer, "endNet", strlen("endNet")) == 0)
		{
			if(!feof(fIn))
			{
				if(fgets(buffer, BUFFER_SIZE, fIn) == NULL)
				{
					fclose(fIn);
					return 0;
				}
				return badFormat;
			}
			else
			{
				fclose(fIn);
				return 0;
			}
		}

		if(strncmp(buffer, "endNode", 7) == 0)
		{
			if(connCounter != listConnCount)
			{
				return badFormat;
			}

			connCounter = 0;
			listConnCount = 0;
			continue;
		}

		if((buffer[0] != '#') && (strchr(buffer, ',') != 0))
		{
			sscanf(buffer, "%d, %d", &nodeIDCount, &connCounter);
			continue;
		}
		listConnCount++;
				
	}
	fclose(fIn);
	return 0;

}

unsigned int parseCommandLine(int argCount, char* argArray[], struct commandLineParams* z);

#endif
