#ifndef BINARY_TREE
#define BINARY_TREE

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

node* create(int data);
node* insertLeft(node* root, int data); // TO DO
node* insertRight(node* root, int data); // TO DO

#endif