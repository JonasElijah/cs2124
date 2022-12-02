#ifndef MESSAGE_HEADER
#define MESSAGE_HEADER
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Message
{
    int messageID;
    int startTime;
    int startNode;
    int endNode;
    int currentNode;
    int endTime;
}message;

message* initMessage(int messageID, int startTime, int startNode, int endNode, int currentNode, int endTime);
int destroyMessage(message* msg);
int printMessage(message* msg);

#endif

