#include "queue.h"

Queue* createQueue()
{
   Queue* q = (Queue*)malloc(sizeof(listADT));
   q->head = NULL;
   q->tail = NULL;
   return q;
}

int enQueue(Queue* q, void* d)
{
   listADT* temp = (listADT*)malloc(sizeof(listADT));
   temp->data = d;
   temp->next = NULL;
   
   if(q->tail == NULL && q->head == NULL)
   {
      q->head = temp;
      q->tail = temp;
   }
   else
   {
        q->tail->next = temp;
        q->tail = temp;
   }
   
   return 0;
}

int deQueue(Queue* q)
{
   listADT* temp = q->head;
   q->head = q->head->next;
   free(temp);
   return 0;
}