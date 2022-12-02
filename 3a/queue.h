#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct listADT
{
    void* data;
    struct listADT* next;
}listADT;

typedef struct queue
{
    struct listADT* head;
    struct listADT* tail;
}Queue;


Queue* createQueue();
int enQueue(Queue* q, void* d);
int deQueue();
#endif