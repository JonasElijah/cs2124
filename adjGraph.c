#include "adjGraph.h"

graphError createMat(unsigned int nodeCount, unsigned short*** matrix)
{
    for(int i = 0; i < nodeCount; ++i)
    {
        for(int count = 0; count < nodeCount; ++count)
        {
            *matrix[i][count] = 1;
        }
    }
}

graphError connectMat(unsigned int srcNodeIdx, unsigned int connNodeIdx, unsigned short*** matrix)
{
    matrix[srcNodeIdx][connNodeIdx] = 0;
}