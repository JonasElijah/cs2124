#include <stdio.h>
#include <stdlib.h>
#include "rns.h"
#include "node.h"

int main(int argc, char* argv[])
{
    struct commandLineParams cmdParams; 
    int status = parseCommandLine(argc, argv, &cmdParams);
        
    if(status != 0)
    {
	    getErrorString(NO_CMD_LINE);
        return NO_CMD_LINE;
    }

   int format_status = formatCheck(cmdParams.fileName);
   if(format_status != 0)
   {
       printf("%d", format_status);
       getErrorString(format_status);
       return format_status;
   }

    FILE* fIn = fopen(cmdParams.fileName, "r");

    if(fIn == NULL)
    {
        getErrorString(emptyFile);
        return emptyFile;
    }
 
  

    int numOfNodes = getNumOfNodes(fIn);
    Node nodeList[numOfNodes];
    int getNode_status =  getNode(nodeList, cmdParams.fileName);
    
    if(getNode_status != 0)
    {
        getErrorString(getNode_status);
        return getNode_status;
    }

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
    if(argCount <= 2)
    {
        return NO_CMD_LINE;
    }

    for(; idx < argCount; idx++)
    {
        switch(argArray[idx][1])
        {
            case 'n': 
                strcpy(z->fileName, argArray[idx+1]);
                idx++;
                break;
            case 'h': 
         	return CMD_LINE_ERR;
            default:
                return CMD_LINE_ERR;	                
        }
    }
    
    return 0;
}
