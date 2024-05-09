#include <stdio.h>
#include <stdlib.h>

// Define the structure of the node
typedef struct Node {
    char data;          // Stores the data of the node
    struct Node* next;  // Pointer to the next node in the list
    struct Node* previous;  // Pointer to the previous node in the list
} Node;

// Create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Assigns memory for a new node
    newNode->data = data;                         // Assigns the data to the new node
    newNode->next = NULL;                         // Sets the next node as NULL
    newNode->previous = NULL;                     // Sets the previous node as NULL
    return newNode;                               // Returns the pointer to the new node created
}

// Insert node at the end of the list
Node* insertNode(Node* head, char data) {
    Node* newNode = createNode(data);  // Creates a new node with the provided data
    if (head == NULL) {
        return newNode;  // If the list is empty, the new node becomes the head of the list
    }

    Node* temp = head;  // Creates a temporary node to traverse the list
    while (temp->next != NULL) {
        temp = temp->next;  // Advances to the last node of the list
    }

    temp->next = newNode;  // Sets the next of the last node as the new node
    newNode->previous = temp;  // Sets the previous node of the new node as the last node
    return head;           // Returns the head of the list
}

// Print the list
void printList(Node* head) {
    Node* temp = head;  // Creates a temporary node to traverse the list
    while (temp != NULL) {
        printf("%c ", temp->data);  // Prints the data of the current node
        temp = temp->next;          // Advances to the next node in the list
    }
    printf("\n");  // Prints a newline at the end of the list
}

// Move a node with a specific value to the end of the list
Node* moveNodeToEnd(Node* head, char data) {
    Node* temp = head;      // Creates a temporary node to traverse the list
    Node* nodeToMove = NULL;  // Initializes a pointer for the node to move as NULL

    // Finds and moves the node with the specific value to the end of the list
    while (temp != NULL) {
        if (temp->data == data) {
            nodeToMove = temp;  // Stores the node to move
            if (temp->previous != NULL) {
                temp->previous->next = temp->next;  // Updates the pointer of the previous node to the node to move
            }
            if (temp->next != NULL) {
                temp->next->previous = temp->previous;  // Updates the pointer of the next node to the node to move
            }
            temp = temp->next;  // Advances to the next node in the list
            nodeToMove->next = NULL;  // Sets the next of the node to move as NULL
            nodeToMove->previous = NULL;  // Sets the previous of the node to move as NULL
        } else {
            temp = temp->next;  // Advances to the next node in the list
        }
    }

    // Adds the moved node to the end of the list
    if (nodeToMove != NULL) {
        temp = head;  // Resets the temporary node to the start of the list
        while (temp->next != NULL) {
            temp = temp->next;  // Advances to the last node in the list
        }
        temp->next = nodeToMove;  // Sets the next of the last node as the node to move
        nodeToMove->previous = temp;   // Sets the previous of the node to move as the last node
    }

    return head;  // Returns the head of the list
}

int main() {
    Node* head = NULL;  // Initializes the head of the list as NULL

    // Create the list
    head = insertNode(head, 'A');  // Inserts the node 'A' into the list
    head = insertNode(head, 'B');  // Inserts the node 'B' into the list
    head = insertNode(head, 'C');  // Inserts the node 'C' into the list
    head = insertNode(head, 'D');  // Inserts the node 'D' into the list
    head = insertNode(head, 'E');  // Inserts the node 'E' into the list

    // Print the list
    printList(head);  // Prints the nodes of the list

    // Move the node with the value 'D' to the end of the list
    head = moveNodeToEnd(head, 'D');  // Moves the node with the value 'D' to the end of the list

    // Print the list again
    printList(head);  // Prints the nodes of the updated list

    return 0;  
}