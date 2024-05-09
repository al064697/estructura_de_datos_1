#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// We define the structure for the nodes of the stack
typedef struct node {
    char data;              // Stores the data of the node
    struct node *next;      // Pointer to the next node in the stack
} Node;

// We define the structure for the stack
typedef struct list {
    Node *head;             // Pointer to the first node of the stack
    int size;               // Stores the current size of the stack
} Stack;

// Function to create a new node
Node* createNode(char data) {
    Node *newNode = (Node*)malloc(sizeof(Node));  // Assigns memory for a new node
    newNode->data = data;                         // Stores the data in the node
    newNode->next = NULL;                         // Initializes the pointer to the next node as NULL
    return newNode;                               // Returns the new node created
}

// Function to create a new stack
Stack* createStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack)); // Assigns memory for a new stack
    stack->head = NULL;                           // Initializes the pointer to the first node as NULL
    stack->size = 0;                              // Initializes the size of the stack as 0
    return stack;                                 // Returns the new stack created
}

// Function to add a node to the beginning of the stack
void push(Stack *stack, Node *node) {
    node->next = stack->head;     // The next of the new node points to the node that is currently at the top of the stack
    stack->head = node;           // The new node becomes the new top of the stack
    stack->size++;                // Increases the size of the stack
}

// Function to remove a node from the beginning of the stack
Node* pop(Stack *stack) {
    Node *node = stack->head;     // Stores the node that is at the top of the stack
    stack->head = node->next;     // The next node in the stack becomes the new top of the stack
}