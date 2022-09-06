#ifndef NODE_HEADER
#define NODE_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL_MARKER '\0'
#define BUFFER_SIZE 1024
#define COMMA_MARKER ','

enum errorCodes{emptyFile, noConn, createNodeError, getListconnError, destroyNodeError, printNodeError};

typedef struct node Node;

struct node
{
    unsigned int nodeID;
    unsigned int connCount;
    unsigned int* listConn;
};

void getNode(Node x[]);
void createNode(char* buffer, Node x[],int y);
void getListconn(char* buffer, Node x[],int y, int i);
void destroyNode(Node x[], int y);
void printNode(Node x);
void getErrorString(int x);

#endif