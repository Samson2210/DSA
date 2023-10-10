#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

// Creating a new node returing the new node
TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode)
    {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

TreeNode *insert(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

TreeNode* delete(TreeNode* root,int data){
    if(root==NULL)
    return root;

    // Recursive calls for ancestors of node to be deleted
    if(root->data > data){
        root->left = delete(root->left, data);
        return root;
    }
    else if(root->data < data){
        root->right = delete(root->right, data);
        return root;
    }

    // We reach here when root is the node to be deleted.

    // If one of the children is empty
    if (root->left == NULL) {
        TreeNode* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        TreeNode* temp = root->left;
        free(root);
        return temp;
    }
    
    // If both children exist
    else{
        TreeNode* succParent= root;

        // Find successor
        TreeNode* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->data = succ->data;
 
        // Delete Successor and return root
        free(succ);
        return root;
    }

}