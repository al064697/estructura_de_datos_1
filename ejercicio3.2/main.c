#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Función para crear un nuevo nodo
struct TreeNode* newNode(char data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Función para realizar el recorrido en preorden del árbol
void preOrder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data); // Visita el nodo raíz
        preOrder(root->left);       // Recorre el subárbol izquierdo
        preOrder(root->right);      // Recorre el subárbol derecho
    }
}

int main() {
    // Construyendo el árbol con las letras proporcionadas por el usuario
    printf("Ingrese la letra para el nodo raíz: ");
    char letter;
    scanf(" %c", &letter);
    struct TreeNode* root = newNode(letter);

    printf("Desea agregar un nodo a la izquierda de %c? (s/n): ", letter);
    char choice;
    scanf(" %c", &choice);
    if (choice == 's') {
        printf("Ingrese la letra para el nodo izquierdo de %c: ", letter);
        scanf(" %c", &letter);
        root->left = newNode(letter);
    }

    printf("Desea agregar un nodo a la derecha de %c? (s/n): ", letter);
    scanf(" %c", &choice);
    if (choice == 's') {
        printf("Ingrese la letra para el nodo derecho de %c: ", letter);
        scanf(" %c", &letter);
        root->right = newNode(letter);
    }

    printf("Recorrido en preorden del árbol binario:\n");
    preOrder(root);

    return 0;
}
