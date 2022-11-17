#ifndef NODE_HEADER
#define NODE_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "route.h"

#define COMMENT_MARKER '#'
#define NULL_MARKER '\0'
#define BUFFER_SIZE 1024
#define COMMA_MARKER ','
#define NETWORK_SIZE 20

enum errorCodes{emptyFile = 1, noConn, createNodeError, getListconnError, destroyNodeError, printNodeError, badFormat};

typedef struct node 
{
    unsigned int nodeID;
    unsigned int connCount;
    unsigned int* listConn;
    unsigned int queueDelay;
    Route routes[NETWORK_SIZE];
}Node;

int getNode(Node x[], FILE* y);
int createNode(char* buffer, Node* x,int y);
int getListconn(char* buffer, Node* x,int y, int i);
int destroyNodes(Node x[], int y);
int printNode(Node x);
void getErrorString(int x);

#endif
