#ifndef QUEUE_H
#define QUEUE_h
#include <stdlib.h>
#include <stdio.h>

typedef struct message
{
    void* data;
    struct message* next;
}Message;

typedef struct queue
{
    struct message* head;
    struct message* tail;
}Queue;

Queue* createQueue();
int enQueue(Queue* q, void* m);
Message* deQueue(Queue* q);
#endif