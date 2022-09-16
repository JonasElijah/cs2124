#ifndef UTIL_HEADER
#define UTIL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMENT_MARKER '#'

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

#endif