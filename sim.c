#include "sim.h"
#include "Util.h"

int getSim(char x[], Sim y[])
{
    bool endOfFile = false;
    FILE* f = fopen(x, "r");
    if(f == NULL)
        {
    	    return emptyFile;
        }
    
    int msgCount = 0, z = 0;
    char buff[BUFFER_SIZE];
    while(!endOfFile)
    {
        enum simulationCmd sim;
        fgets(buff, BUFFER_SIZE, f);
        if(strchr(buff,'#') != 0)
        {
	    if(buff[0] == '#')
	    {
		continue;
	    }
            commentOut(buff);
        }

        if(strstr(buff,"msg") != 0)
        {
            sim = msg;
        }
        else if (strstr(buff,"rep") != 0)
        {
            sim = rep;
        }
        else if(strstr(buff,"endSim") != 0)
        {
            sim = endSim;
        }
        else
        {
            printf("ERROR");
        }

        switch(sim)
        {
            case msg:
                createSim(buff, y, msgCount, msg);
                msgCount++;
                break;
            case rep:
                if(strstr(buff,"rep,") != 0)
                 {
                     unsigned int numID = getNodeID(buff);
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

                break;
            case endSim:
                printf("end the simulation\n");
                fclose(f);
                endOfFile = true;
                break;
        }
  
    }
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

int createSim(char* buff, Sim* x, int y, int sim)
{
    x[y].command = sim;
    sscanf(buff, "%u,msg,%u,%u,%u", &x[y].timestamp, &x[y].messageID, &x[y].start_node, &x[y].end_node);
    return 0;
}

int destroySim(Sim x)
{

}
