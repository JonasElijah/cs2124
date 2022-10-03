#include "sim.h"
#include "Util.h"

int getSim(char* x, Sim y[])
{
    FILE* f = fopen(x, "r");
    if(f == NULL)
        {
    	    return emptyFile;
        }
    
    int msgCount = 0;
    char buff[BUFFER_SIZE];
    while(!feof(f))
    {
        fgets(buff, BUFFER_SIZE, f);
        commentOut(buff);
        if(buff[0] != '#' && strstr(buff,"msg") != 0 )
        {
            createSim(buff, y, msgCount);
            msgCount++;
        }
       else if (buff[0] != '#' && strstr(buff,"rep") != 0)
       {
            if(strchr((strstr(buff,"rep") + 1), ',') != 0)
            {
                unsigned int numID = getNodeID(buff);
                int z = 0;
                if(y[z].messageID == numID)
                    {
                        printSim(y[z]);
                    }
                while(y[z].messageID != numID)
                {  
                    if(y[z+1].messageID == numID)
                    {
                        printSim(y[z+1]);
                    }
                    z++;
                }
             
            }
            else
            {
                int p = 0;
                for(; p < msgCount; p++)
                {
                    printSim(y[p]);
                }
            }
        
       }
       if(strstr(buff,"endSim") != 0 )
       {
            printf("end the simulation");
       }
    }
    fclose(f);
    return 0;
}

int printSim(Sim x)
{
    printf("Time Start: %u\n", x.timestamp);
    printf("Start Node: %u\n", x.start_node);
    printf("End Node: %u\n", x.end_node);
    printf("Cur Node:  \n");
    printf("Time End:  \n");
    printf("\n");
    return 0;
}

unsigned int getNodeID(char buff[])
{
    unsigned int y, x = 0;
    sscanf(buff,"%u,rep,%u", &y ,&x);
    return x;
}

int createSim(char* buff, Sim* x, int y)
{
    sscanf(buff, "%u,msg,%u,%u,%u", &x[y].timestamp, &x[y].messageID, &x[y].start_node, &x[y].end_node);
    return 0;
}

