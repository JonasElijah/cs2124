#include "Util.h"

void commentOut(char* x)
{
    char* comment = strchr(x,COMMENT_MARKER);
    if(comment != 0)
     {
        size_t len = strlen(comment);
        memset(comment, '\0' ,len);
        *comment = '\n';
    }
} 
/*
int findIndex(char buff[], int val)
{
    int index = 0, i = 0, size = sizeof(buff);
    for(; i < size ;i++)
    {
        if(((int)buff[i]) == val)
        {
            index = i;
        }
    }
    return index;
}
*/