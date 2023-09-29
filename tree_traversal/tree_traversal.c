#include<stdio.h>;
#include "tree_traversal.h"


//INORDER TRAVERSAL
void inorderTraversal(node* root){
    if(root == NULL)
    return;
    inorderTraversal(root->left);
    printf("%d->", root->data);
    inorderTraversal(root->right);
}

//  PREORDER TRAVERSAL
void preorderTraversal(node* root){
    if(root == NULL)
    return;
    printf("%d->", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


