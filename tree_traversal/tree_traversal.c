#include<stdio.h>
#include "tree_traversal.h"


//INORDER TRAVERSAL
void inorderTraversal(TreeNode* root){
    if(root == NULL)
    return;
    inorderTraversal(root->left);
    printf("%d->", root->data);
    inorderTraversal(root->right);
}

//  PREORDER TRAVERSAL
void preorderTraversal(TreeNode* root){
    if(root == NULL)
    return;
    printf("%d->", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//POSTORDER TRAVERSAL
void postorderTraversal(TreeNode* root){
    if(root==NULL)
    return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->data);
}

