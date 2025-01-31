#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    printf("%d ", root->data);

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left);

    // Visit the root node
    printf("%d ", root->data);

    inOrderTraversal(root->right);
}

// Function for post-order traversal
void postOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    // Visit the root node
    printf("%d ", root->data);
}

void main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Pre-order traversal of the binary tree:\n");
    preorderTraversal(root);
}