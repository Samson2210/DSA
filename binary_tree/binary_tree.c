#include<stdio.h>
#include "binary_tree.h"


//Creating a new node returing the new node
node* create(int data){
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

