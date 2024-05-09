#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the node
typedef struct Node {
    char name[50];          // Stores the student's name
    int age;                // Stores the student's age
    char phone[15];         // Stores the student's phone number
    struct Node* next;      // Pointer to the next node in the circular list
} Node;

// Create a new node
Node* createNode(char* name, int age, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Assigns memory for a new node
    strcpy(newNode->name, name);                  // Copies the provided name to the node
    newNode->age = age;                           // Assigns the provided age to the node
    strcpy(newNode->phone, phone);                // Copies the provided phone number to the node
    newNode->next = newNode;                      // Points to itself as it's the only node in the circular list
    return newNode;                               // Returns the pointer to the newly created node
}

// Insert node into the circular list
Node* insertNode(Node* last, char* name, int age, char* phone) {
    if (last == NULL) {
        return createNode(name, age, phone);  // If the list is empty, create a new node
    }

    Node* newNode = createNode(name, age, phone);  // Creates a new node with the provided data
    newNode->next = last->next;                    // The next of the new node points to the next of the last
    last->next = newNode;                          // The next of the last points to the new node

    return newNode;  // Returns the newly inserted node
}

// Search for a node in the circular list
Node* searchNode(Node* last, char* name) {
    Node* temp = last->next;  // Starts from the next of the last node
    do {
        if (strcmp(temp->name, name) == 0) {
            return temp;  // Returns the node if the name is found
        }
        temp = temp->next;  // Moves to the next node
    } while (temp != last->next);  // Continues until the entire list is traversed

    return NULL;  // Returns NULL if the node is not found in the list
}

// Modify a node in the circular list
void modifyNode(Node* node, char* name, int age, char* phone) {
    strcpy(node->name, name);   // Updates the student's name in the node
    node->age = age;            // Updates the student's age in the node
    strcpy(node->phone, phone); // Updates the student's phone in the node
}

// Delete a node from the circular list
Node* deleteNode(Node* last, char* name) {
    if (last == NULL) {
        return NULL;  // If the list is empty, no node can be deleted
    }

    Node *current = last, *previous = NULL;
    while (strcmp(current->name, name) != 0) {
        previous = current;       // Updates the previous node
        current = current->next;  // Moves to the next node

        if (current == last && strcmp(current->name, name) != 0) {
            printf("Node with the name %s not found\n", name);
            return last;  // If the entire list is traversed and the name is not found, no node is deleted
        }
    }

    if (current->next == current) {
        last = NULL;  // If there's only one node in the list, last is set to NULL
    } else if (current == last) {
        previous->next = current->next;  // If the node to delete is the last, the next of the previous node is updated
        last = previous;                 // The last node is updated
    } else {
        previous->next = current->next;  // If the node to delete is in the middle of the list, the next of the previous node is updated
    }

    free(current);  // The memory of the deleted node is freed

    return last;  // Returns the pointer to the last node of the updated list
}

int main() {
    Node* last = NULL;  // Initializes the pointer to the last node as NULL
    char name[50];      // Stores the student's name
    int age;            // Stores the student's age
    char phone[15];     // Stores the student's phone number
    int option;         // Stores the option selected by the user
    do {
        printf("\n1. Insert student\n");
        printf("2. Search student\n");
        printf("3. Modify student\n");
        printf("4. Delete student\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the student's name: ");
                scanf("%s", name);
                printf("Enter the student's age: ");
                scanf("%d", &age);
                printf("Enter the student's phone: ");
                scanf("%s", phone);
                last = insertNode(last, name, age, phone);
                break;
            case 2:
                printf("Enter the name of the student to search: ");
                scanf("%s", name);
                Node* found = searchNode(last, name);
                if (found != NULL) {
                    printf("Student found: %s, %d, %s\n", found->name, found->age, found->phone);
                } else {
                    printf("Student not found\n");
                }
                break;
            case 3:
                printf("Enter the name of the student to modify: ");
                scanf("%s", name);
                Node* toModify = searchNode(last, name);
                if (toModify != NULL) {
                    printf("Enter the new name of the student: ");
                    scanf("%s", name);
                    printf("Enter the new age of the student: ");
                    scanf("%d", &age);
                    printf("Enter the new phone of the student: ");
                    scanf("%s", phone);
                    modifyNode(toModify, name, age, phone);
                } else {
                    printf("Student not found\n");
                }
                break;
            case 4:
                printf("Enter the name of the student to delete: ");
                scanf("%s", name);
                last = deleteNode(last, name);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 5); 

    return 0; 
}