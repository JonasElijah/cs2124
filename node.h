#ifndef NODE_HEADER
#define NODE_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL_MARKER '\0'
#define BUFFER_SIZE 1024
#define COMMA_MARKER ','

enum errorCodes{emptyFile = 1, noConn, createNodeError, getListconnError, destroyNodeError, printNodeError, badFormat};

typedef struct node Node;

struct node
{
    unsigned int nodeID;
    unsigned int connCount;
    unsigned int* listConn;
};

int getNode(Node x[], char* y);
int createNode(char* buffer, Node* x,int y);
int getListconn(char* buffer, Node* x,int y, int i);
int destroyNodes(Node x[], int y);
int printNode(Node x);
void getErrorString(int x);

#endif
