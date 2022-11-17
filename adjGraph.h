#ifndef GRAPH_HEADER
#define GRAPH_HEADER

typedef enum GRAPH_ERRORS
{
    NOERROR = 0,
    GRAPH_ERROR = -1
}graphError;

graphError createMat(unsigned int nodeCount, unsigned short*** matrix);
graphError connectMat(unsigned int srcNodeIdx, unsigned int connNodeIdx, unsigned short*** matrix);
graphError insertMat(unsigned short*** matrix, unsigned int idx);
graphError removeMat(unsigned short*** matrix, unsigned int idx);
graphError destroyMat(unsigned short** matrix);


#endif