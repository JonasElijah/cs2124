#ifndef MAIN_HEADER
#define MAIN_HEADER
#include "message.h"

#define BUFFER_SIZE 1024
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