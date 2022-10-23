#ifndef SIM
#define SIM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"


enum simulationCmd{msg = 1, rep, endSim};

typedef struct simulation
{
    unsigned int timestamp;
    enum simulationCmd command;
    unsigned int messageID;
    unsigned int start_node;
    unsigned int end_node;
}Sim;

int getSim(char x[], Sim y[]);
int printSim(Sim x);
int findIndex(char buff[], int val);
unsigned int getNodeID(char buff[]);
int createSim(char* buff, Sim* x, int y, int sim);
int destroySim(Sim x[]);


#endif
