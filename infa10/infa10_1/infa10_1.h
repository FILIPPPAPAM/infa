#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct TreeNode {
    char word[50];
    int frequency;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(char* word);
TreeNode* insertNode(TreeNode* root, char* word);
void inorderTraversal(TreeNode* root);
void reverseInorderTraversal(TreeNode* root);
void freeTree(TreeNode* root);

#endif
