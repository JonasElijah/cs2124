#ifndef ROUTE_H
#define ROUTE_H

typedef struct route
{
    unsigned int finalDestinationID;
    unsigned int nextHopNodeID;
    unsigned int hopCount;
}Route;



#endif