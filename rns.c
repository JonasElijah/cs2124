#include "rns.h"
#include "sim.h"

int main(int argc, char* argv[])
{
    struct commandLineParams cmdParams; 
    int cmdline_status = parseCommandLine(argc, argv, &cmdParams);
    
    if(cmdline_status != 0)
    {
        getErrorString(cmdline_status);
        return cmdline_status;
    }

   int format_status = formatCheck(cmdParams.fileName);
   if(format_status != 0)
   {
       getErrorString(format_status);
       return format_status;
   }

    FILE* fIn = fopen(cmdParams.fileName, "r");
    if(fIn == 0)
    	return emptyFile;

    int numOfNodes = getNumOfNodes(fIn);
    Node nodeList[numOfNodes];
    int getNode_status = getNode(nodeList, cmdParams.fileName);
    
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

    printf("\n");
  
    /*destroyNodes(nodeList, numOfNodes);*/
    FILE* fIn2 = fopen(cmdParams.simName, "r");
    if(fIn2 == 0)
    	return emptyFile;

    int numOfMsg = getNumMessages(fIn2);
    Sim simulation[numOfMsg];
    int getMessages_Status = getSim(cmdParams.simName, simulation);
    
    fclose(fIn);   
    fclose(fIn2);
    return 0; 

}

unsigned int parseCommandLine(int argCount, char* argArray[], struct commandLineParams* z)
{
    int idx = 1;
    if(argCount < MIN_COMMAND_LINE_ARGUMENTS)
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
            case's':
                strcpy(z->simName, argArray[idx+1]);
                idx++;
                break;
            case 'h': 
         	return CMD_LINE_ERR;
            default:
                return CMD_LINE_ERR;	                
        }
    }
    /*
    if((fopen(z->simName, "r") == 0) || (fopen(z->fileName, "r") == 0))
    {
        return emptyFile;
    }
    */
    return 0;
}

