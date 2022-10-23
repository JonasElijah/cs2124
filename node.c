#include "node.h"
#include "Util.h"

int createNode(char* buffer, Node* x,int y)
{
   sscanf(buffer, "%u, %u", &x[y].nodeID, &x[y].connCount); 
   int connCountx = x[y].connCount;
   x[y].listConn = (unsigned int*)malloc(connCountx *sizeof(unsigned int));
   if(x[y].connCount == 0)
   {
      return createNodeError;
   }
   return 0;
}

int getListconn(char* buffer, Node x[],int y, int i)
{
   sscanf(buffer, "%u", &x[y].listConn[i]);
   if(i != 0)
   {
  	if(x[y].listConn[i] == x[y].listConn[i - 1])
  	{
      return getListconnError;
   }
   }

   return 0;
}

int destroyNodes(Node x[], int y)
{
   x->nodeID = 0;
   x->connCount = 0;
   int count = 0;
   for(;count < y; count++)
   {
      free(x[y].listConn);
   }
   return 0;
}

int printNode(Node x)
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
   printf("\n");
   return 0;
}

void getErrorString(int x)
{
   if(x == 1)
   {
      printf("ERROR CODE 1: File is empty or doesn't exist\n");
   }
	
   if(x == noConn)
   {
      printf("ERROR CODE 2: There should at least be one connection\n");
   }

   if(x == createNodeError)
   {
      printf("ERROR CODE 3: createNode function used incorrectly\n");
   }
   
   if(x == getListconnError)
   {
      printf("ERROR CODE 4: getListconn function used incorrectly\n");
   }

   if(x == destroyNodeError)
   {
      printf("ERROR CODE 5: destroyNode function used incorrectly\n");
   }

   if(x == printNodeError)
   {
      printf("ERROR CODE 6: printNode function used incorrtly\n");
   }

   if(x == badFormat)
   { 
      printf("ERROR CODE 7: Bad file format\n");	
   }

   if(x == 8)
   {
      printf("ERROR CODE 8: The notation for the command line is -n {filename}");
   }

   if(x == 9)
   {
      printf("ERROR CODE 9: The notation for the command line is -n {filename}");
   }
}

int getNode(Node x[], FILE* y)
{
   
    //FILE* fIn = fopen(y, "r");
    int connNum = 0, nodeNum = 0;
    char buffer[BUFFER_SIZE];
    while(!feof(y))
    {
        fgets(buffer, BUFFER_SIZE, y); 
        commentOut(buffer); 
        if(buffer[0] == NULL_MARKER || buffer[0] == '\n')
        {
            continue;
        }
        
        if(strncmp(buffer, "endNode", strlen("endNode")) == 0)
        {
            nodeNum++;
            connNum = 0;
            continue;
        }

        if(strncmp(buffer, "endNet", strlen("endNet")) == 0)
        {
            break;
        }

        if(strchr(buffer,COMMA_MARKER)!= 0)
        {
            int createNode_status = createNode(buffer, x, nodeNum);
            if(createNode_status != 0)
            {
                getErrorString(createNode_status);
                return createNode_status;
            }
        }
        else
        {
            int getListconn_status = getListconn(buffer, x, nodeNum, connNum);

            if(getListconn_status != 0)
            {
            	getErrorString(getListconn_status);
               return getListconn_status;
            }
            connNum++;
        }
 
    }
    
   //  fclose(fIn);
   return 0;
}
