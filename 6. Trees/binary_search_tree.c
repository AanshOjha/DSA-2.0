#include <stdio.h>
#include <stdlib.h>

// Structure for a BST Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    
    return root;
}

void modifyNode(struct Node* root, int oldValue, int newValue) {
    if (root == NULL) return;

    // Search for the node with oldValue
    if (oldValue < root->data)
        modifyNode(root->left, oldValue, newValue);
    else if (oldValue > root->data)
        modifyNode(root->right, oldValue, newValue);
    else
        root->data = newValue;  // Modify the node's value
}

// Function to find the minimum value node in the right subtree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else {
        // No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // 1 Child
        else if (root->left == NULL || root->right == NULL) {
            struct Node* temp;
            if (root->left == NULL) {
                temp = root->right;
            }
            else {
                temp = root->left;
            }
            free(root);
            return temp;
        }

        // 2 children
        else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Function to search for a node in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Function for in-order traversal of BST (sorted order)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function to test BST operations
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    printf("\nSearch of element: %d", search(root, 60));
    printf("In-order traversal of BST: ");
    inorder(root);
    printf("\n");
    
    // root = deleteNode(root, 30);
    // printf("After deleting 30, In-order traversal: ");
    // inorder(root);
    // printf("\n");
    
    // int key = 60;
    // struct Node* found = search(root, key);
    // if (found)
    //     printf("Element %d found in BST.\n", key);
    // else
    //     printf("Element %d not found in BST.\n", key);


    
    
    return 0;
}
