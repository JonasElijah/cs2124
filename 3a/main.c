#include "main.h"
#include "queue.h"


int main(int argc, char* argv[])
{
    int messageID, startTime, startNode, endNode, currentNode, endTime, count = 0;
    Queue* queue = createQueue();
    message* msg[20];
    FILE* fIn = fopen(argv[1], "r");
    char buff[BUFFER_SIZE];
    while(!feof(fIn))
    {
        int Case = 0;
        fgets(buff, BUFFER_SIZE, fIn);
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
            sscanf(buff, "%u,msg,%u,%u,%u", &startTime, &messageID, &startNode, &endNode);
            msg[count] = initMessage(messageID, startTime, startNode, endNode, currentNode, endTime);
            enQueue(queue, &msg[count]);
            count++;
        }
       
       if(strstr(buff,"endSim") != 0)
        {
            printf("end of simulation\n");
        }
    }
    fclose(fIn);
    return 0;
}