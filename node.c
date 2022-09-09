#include "node.h"

#define COMMENT_MARKER '#'
void commentOut(char* x)
{
    char* comment = strchr(x,COMMENT_MARKER);//points to the address to where # is located, returns null is not found
    if(comment != 0)
     {
        size_t len = strlen(comment);//gets the length of comment and stores it in len
        memset(comment, '\0' ,len);//sets all characters of comment to NULL
        *comment = '\n';
    }
}


void createNode(char* buffer, Node x[],int y)
{
   sscanf(buffer, "%u, %u", &x[y].nodeID, &x[y].connCount);
   int connCountx = x[y].connCount;
   x[y].listConn = (unsigned int*)malloc(connCountx *sizeof(unsigned int));
}

void getListconn(char* buffer, Node x[],int y, int i)
{
   sscanf(buffer, "%u", &x[y].listConn[i]);
}

void destroyNode(Node x[], int y)
{
   x[y].nodeID = NULL_MARKER;
   x[y].connCount = NULL_MARKER;
   free(x[y].listConn);
}

void printNode(Node x)
{
   printf("Node ID: %u\n", x.nodeID);
   printf("Connection Count: %u\n", x.connCount);
   int i = 0;
   int index = 1;
   while(i != x.connCount )
   {
      printf("Connection %d: %u\n", index, x.listConn[i]);
      index++;
      i++;
   }
}

void getErrorString(int x)
{
   if(x == 0)
   {
      printf("Error: File is empty or doesn't exist\n");
   }

   if(x == 1)
   {
      printf("Error: There should at least be one connection\n");
   }

   if(x == 2)
   {
      printf("Error: createNode function used incorrectly\n");
   }
   
   if(x == 3)
   {
      printf("Error: getListconn function used incorrectly\n");
   }

   if(x == 4)
   {
      printf("Error: destroyNode function used incorrectly\n");
   }

   if(x == 5)
   {
      printf("Error: printNode function used incorrtly\n");
   }
}

int getNode(Node x[], char* y)
{
//-----------------------------------------------//
//  Opening file, initializing variable and      //
//  creating an array of structs called nodeList //                                            
//-----------------------------------------------//
    FILE* fIn = fopen(y, "r");
    enum errorCodes error;
    int connNum = 0, nodeNum = 0;
    
    if(fIn == 0)// tests to see if file is empty
    {
        error = emptyFile;
        getErrorString(error);
    }

//-----------------------------------------------//
//  Reading text file line by line, stripping    //
//  comments and initializing node structure     //
//  members.                                     //      
//-----------------------------------------------//
    char buffer[BUFFER_SIZE];
    while(!feof(fIn))
    {
        fgets(buffer, BUFFER_SIZE, fIn); //reads a line from a stream then stores it in buffer
        commentOut(buffer); //gets rid of comments
      

        //tests to see if the first element of buffer is equal to either NULL or \n
        if(buffer[0] == NULL_MARKER || buffer[0] == '\n')
        {
            continue;
        }
        
        //compares buffer to string endNode. If true, then increment nodeList array by 1 and set listConn array to element 0
        if(strncmp(buffer, "endNode", strlen("endNode")) == 0)
        {
            nodeNum++;
            connNum = 0;
            continue;
        }

        //compares buffer to string endNet. If true, then end while loop.
        if(strncmp(buffer, "endNet", strlen("endNet")) == 0)
        {
            break;
        }

        //If comma exists in buffer, then initialize node struct with the values inside buffer
        if(strchr(buffer,COMMA_MARKER)!= 0)
        {
            createNode(buffer, x, nodeNum);
            //If connection count is equal to zero then break out of while loop
            if(x[nodeNum].connCount == 0)
            {
                error = noConn;
                getErrorString(error);
                break;
            }
        }
        else
        {
            getListconn(buffer, x, nodeNum, connNum);

            if(connNum != 0)
            {
               if(x[nodeNum].listConn[connNum] == x[nodeNum].listConn[connNum - 1])
               {
                  return badFormat;
               }
            }
            connNum++;
        }
 
    }
    
    fclose(fIn);
   return 0;
}
