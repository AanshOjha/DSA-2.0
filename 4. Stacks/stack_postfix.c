#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure definition
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* exp) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            // If the character is a digit, convert it to an integer and push onto the stack
            push(&stack, exp[i] - '0');
        } else if (exp[i] == ' ') {
            // Skip spaces
            continue;
        } else {
            // If the character is an operator, pop two elements from the stack, apply the operator and push the result back onto the stack
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            switch (exp[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
            }
        }
        
        // Print the stack status after each step
        printf("Stack status: ");
        for (int j = 0; j <= stack.top; j++) {
            printf("%d ", stack.data[j]);
        }
        printf("\n");
    }

    // The final result will be the only element left in the stack
    return pop(&stack);
}

// Main function
void main() {
    char exp[] = "5 1 2 + 4 * + 3 -";
    printf("Postfix expression: %s\n", exp);
    int result = evaluatePostfix(exp);
    printf("Result of the postfix expression: %d\n", result);
}
