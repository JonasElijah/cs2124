#include "queue.h"

Queue* createQueue()
{
   Queue* q = (Queue*)malloc(sizeof(Queue));
   q->head = '\0';
   q->tail = '\0'; 
   return q;
}

int enQueue(Queue* q, void* m)
{
   Message* temp = (Message*)malloc(sizeof(Message));
   temp->data = m;
   temp->next = '\0';

   if(q->tail == '\0')
   {
      q->head = temp;
      q->tail = temp;
   }

   q->tail->next = temp;
   q->tail = temp;
   return 0;
}

Message* deQueue(Queue* q)
{
   Message* temp = q->head;
   q->head = q->head->next;
   return temp;
}