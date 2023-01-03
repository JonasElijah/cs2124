#include "tree.h"

treeADT* initBranch(void* userdata, unsigned int usersize, treeADT* parent, int bf)
{
    treeADT* temp = malloc(sizeof(treeADT));
    if(parent == NULL)
    {
        temp->parent = temp;
    }
    else
    {
        temp->parent = parent;
    }
    temp->data = userdata;
    temp->size = usersize;
    temp->balance = bf;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int rec_insertBranch(struct treeADT** treeRoot, struct treeADT* parentTree, void* userdata, unsigned int usersize, int bf)
{
    treeADT* root = *treeRoot;
    if(root == NULL)
    {
        *treeRoot = initBranch(userdata, usersize, parentTree, bf);
        return 0;
    }

    if(root->size > usersize)
    {
        root->parent->balance--;
        return rec_insertBranch(&root->left, root, userdata, usersize, bf+1);
    }
    else
    {
        root->parent->balance++;
        return rec_insertBranch(&root->right, root, userdata, usersize, bf+1);
    }
    return 0;
}

void insertBranch(struct treeADT** treeRoot, void* userdata, unsigned int usersize)
{
    rec_insertBranch(treeRoot, *treeRoot, userdata, usersize, 0);   
}



int findBranch(struct treeADT* currTree, void* userdata)
{
    if(strncmp((char*)userdata, (char*)currTree->data , sizeof(userdata)) == 0)
    {
        return 0;
    }

    if(currTree->left != NULL)
    {
        findBranch(currTree->left, userdata);
    }

    if(currTree->right != NULL)
    {
        findBranch(currTree->right, userdata);
    }
    return 0;
}

treeADT* rightRotate(struct treeADT* treeRoot)
{
    treeADT* tempRoot = treeRoot->left;
    treeADT* tempNode;
    if(tempRoot->right != NULL)
    {
        tempNode = tempRoot->right;
    }
    else
    {
        tempNode = tempRoot->left;
    }
    
    tempRoot->right = treeRoot;
    tempRoot->left = tempNode;
    return tempRoot;
}

treeADT* leftRotate(struct treeADT* treeRoot)
{
    treeADT* tempRoot = treeRoot->right;
    treeADT* tempNode;
    if(tempRoot->left != NULL)
    {
        tempNode = tempRoot->left;
    }
    else
    {
        tempNode = tempRoot->right;
    }

    tempRoot->right= tempNode;
    tempRoot->left = treeRoot;
    return tempRoot;
}

int balanceTree(treeADT* treeRoot)
{
    
    return 0;
}

