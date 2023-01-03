#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <string.h>

typedef struct treeADT
{
    void* data;
    unsigned int size;
    int balance;
    struct treeADT* parent;
    struct treeADT* left;
    struct treeADT* right;
}treeADT;

treeADT* initBranch(void* userdata, unsigned int usersize, treeADT* parent, int userheight);
void insertBranch(struct treeADT** treeRoot, void* userdata, unsigned int usersize);
int findBranch(struct treeADT* treeRoot, void* userdata);
treeADT* rightRotate(struct treeADT* treeRoot);
treeADT* leftRotate(struct treeADT* treeRoot);
int balanceTree(treeADT* treeRoot);
int destroyBranch(struct treeADT* treeRoot, void* userdata);
int removeBranch(struct treeADT* treeRoot, void* userdata);
#endif