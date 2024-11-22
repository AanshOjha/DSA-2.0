#include <stdio.h>
#include <stdlib.h>

#define MAX 50 // Define the maximum size of the stack

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d\n", value);
    } else {
        stack->items[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop an element.\n");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}

// Peek at the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No element to peek.\n");
        return -1;
    } else {
        return stack->items[stack->top];
    }
}

void main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(&stack));

    printf("Popped element is %d\n", pop(&stack));

    if (isEmpty(&stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
}
