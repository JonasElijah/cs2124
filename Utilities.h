#ifndef UTIL_HEADER
#define UTIL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMENT_MARKER '#'

void commentOut(char* x)
{
    char* comment = strchr(x,COMMENT_MARKER);//points to the address to where # is located,returns null is not found
    if(comment != 0)
     {
        size_t len = strlen(comment);//gets the length of comment and stores it in len
        memset(comment, '\0' ,len);//sets all characters of comment to NULL
        *comment = '\n';
    }
}




#endif