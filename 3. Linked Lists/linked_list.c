#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ===================================================================================================================

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* new_node = createNode(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = temp->next;
    
}


// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last element
void deleteAtEnd(struct Node** head) {
    // If empty
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    // If one element
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Else
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void main() {
    struct Node* head = NULL;
    int n, data, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("The linked list is: \n");
    displayList(head);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("6. Insert at position\n");
        printf("3. Delete from beginning\n");
        printf("7. Delete at end\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 7:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter the data to insert at position: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &n);
                insertAtPosition(&head, data, n);
                break;
            case 3:
                deleteFromBeginning(&head);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}