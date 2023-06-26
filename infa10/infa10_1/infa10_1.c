#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

TreeNode* createNode(char* word) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->word, word);
    newNode->frequency = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, char* word) {
    if (root == NULL) {
        return createNode(word);
    }

    int cmp = strcmp(word, root->word);
    if (cmp < 0) {
        root->left = insertNode(root->left, word);
    } else if (cmp > 0) {
        root->right = insertNode(root->right, word);
    } else {
        root->frequency++;
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s: %d\n", root->word, root->frequency);
        inorderTraversal(root->right);
    }
}

void reverseInorderTraversal(TreeNode* root) {
    if (root != NULL) {
        reverseInorderTraversal(root->right);
        printf("%s: %d\n", root->word, root->frequency);
        reverseInorderTraversal(root->left);
    }
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
