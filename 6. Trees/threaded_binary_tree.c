#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int isThreaded;  // 1 if the right pointer is a thread
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = 0; // Default: not a thread
    return newNode;
}

// Function to insert a node in a Threaded Binary Tree
struct Node* insert(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    if (root == NULL) 
        return newNode;  // If tree is empty, return new node as root

    struct Node* parent = NULL;
    struct Node* curr = root;

    while (curr != NULL) {
        parent = curr;
        if (data < curr->data) {
            if (curr->left == NULL) {
                curr->left = newNode;
                newNode->right = curr;  // Set thread to successor
                newNode->isThreaded = 1;
                return root;
            }
            curr = curr->left;
        } else {
            if (curr->right == NULL) {
                curr->right = newNode;
                return root;
            } else if (curr->isThreaded) {
                newNode->right = curr->right; // Preserve thread
                newNode->isThreaded = 1;
                curr->right = newNode;
                curr->isThreaded = 0; // Break the old thread
                return root;
            }
            curr = curr->right;
        }
    }
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;

    struct Node* curr = root;

    // Find the leftmost node
    while (curr->left != NULL)
        curr = curr->left;

    // Perform inorder traversal
    while (curr != NULL) {
        printf("%d ", curr->data);

        // If the right pointer is a thread, follow it
        if (curr->isThreaded)
            curr = curr->right;
        else {
            // Else, find the leftmost node in right subtree
            curr = curr->right;
            while (curr != NULL && curr->left != NULL)
                curr = curr->left;
        }
    }
}

int main() {
    struct Node* root = NULL;

    // Insert elements into the Threaded Binary Tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print inorder traversal (should print sorted order)
    printf("Inorder Traversal of Threaded Binary Tree:\n");
    inorder(root);

    return 0;
}