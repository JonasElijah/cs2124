#include "message.h"

message* initMessage(int messageID, int startTime, int startNode, int endNode, int currentNode, int endTime)
{
    message* msg = (message*)malloc(sizeof(message));
    msg->messageID = messageID;
    msg->startTime = startTime;
    msg->startNode = startNode;
    msg->endNode = endNode;
    msg->currentNode = currentNode;
    msg->endTime = endTime;
    return msg;
}

int destroyMessage(message* msg)
{
    free(msg);
    return 0;
}

int printMessage(message* msg)
{
    printf("Time Start: %d\n", msg->startTime);
    printf("Start Node: %d\n", msg->startNode);
    printf("End Node: %d\n", msg->endNode);
    printf("Cur Node:  %d\n", msg->currentNode);
    printf("Time End:  %d\n", msg->endTime);
    printf("\n");
    return 0;
}