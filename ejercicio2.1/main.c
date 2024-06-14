#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Definimos la estructura para los nodos de la pila
typedef struct nodo {
    char dato;              // Almacena el dato del nodo
    struct nodo *siguiente; // Puntero al siguiente nodo en la pila
} Nodo;

// Definimos la estructura para la pila
typedef struct lista {
    Nodo *cabeza;   // Puntero al primer nodo de la pila
    int tamaño;     // Almacena el tamaño actual de la pila
} Pila;

// Función para crear un nuevo nodo
Nodo* crearNodo(char dato) {
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));  // Asigna memoria para un nuevo nodo
    nuevoNodo->dato = dato;                         // Almacena el dato en el nodo
    nuevoNodo->siguiente = NULL;                    // Inicializa el puntero al siguiente nodo como NULL
    return nuevoNodo;                               // Retorna el nuevo nodo creado
}

// Función para crear una nueva pila
Pila* crearPila() {
    Pila *pila = (Pila*)malloc(sizeof(Pila));  // Asigna memoria para una nueva pila
    pila->cabeza = NULL;                        // Inicializa el puntero al primer nodo como NULL
    pila->tamaño = 0;                           // Inicializa el tamaño de la pila como 0
    return pila;                                // Retorna la nueva pila creada
}

// Función para añadir un nodo al principio de la pila
void push(Pila *pila, Nodo *nodo) {
    nodo->siguiente = pila->cabeza;    // El siguiente del nuevo nodo apunta al nodo que actualmente está en la cima de la pila
    pila->cabeza = nodo;               // El nuevo nodo se convierte en la nueva cima de la pila
    pila->tamaño++;                    // Incrementa el tamaño de la pila
}

// Función para sacar un nodo del principio de la pila
Nodo* pop(Pila *pila) {
    Nodo *nodo = pila->cabeza;         // Almacena el nodo que está en la cima de la pila
    pila->cabeza = nodo->siguiente;    // El siguiente nodo en la pila se convierte en la nueva cima de la pila
    pila->tamaño--;                    // Reduce el tamaño de la pila
    return nodo;                       // Retorna el nodo que fue eliminado de la pila
}

// Función para obtener el nodo del principio de la pila sin sacarlo
Nodo* peek(Pila *pila) {
    return pila->cabeza;               // Retorna el nodo que está en la cima de la pila sin eliminarlo
}

// Función para comprobar si la pila está vacía
int estaVacia(Pila *pila) {
    return pila->cabeza == NULL;       // Retorna 1 si la pila está vacía, 0 en caso contrario
}

// Función para comprobar si un carácter es un operador
int esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');  // Retorna 1 si el carácter es un operador, 0 en caso contrario
}

// Función para obtener la precedencia de un operador
int precedencia(char c) {
    switch(c) {
        case '+':
        case '-':
            return 1;  // La precedencia de suma y resta es 1
        case '*':
        case '/':
            return 2;  // La precedencia de multiplicación y división es 2
        default:
            return 0;  // Otros caracteres tienen precedencia 0
    }
}

// Función para convertir una expresión infija a postfija
void infijaAPostfija(char* infija, char* postfija) {
    Pila* pila = crearPila();  // Creamos una pila vacía para almacenar operadores
    int i, j = 0;               // Variables para iteración y para indexar la cadena de salida
    for(i = 0; infija[i] != '\0'; i++) {
        // Si el carácter es un operando, lo añadimos directamente a la expresión postfija
        if(isalpha(infija[i])) {
            postfija[j++] = infija[i];
        } else if(esOperador(infija[i])) {
            // Si el carácter es un operador, sacamos todos los operadores de la pila con mayor o igual precedencia y luego añadimos el operador actual a la pila
            while(!estaVacia(pila) && esOperador(peek(pila)->dato) && precedencia(peek(pila)->dato) >= precedencia(infija[i])) {
                postfija[j++] = pop(pila)->dato;
            }
            push(pila, crearNodo(infija[i]));  // Añadimos el operador actual a la pila
        } else if(infija[i] == '(') {
            // Si el carácter es un paréntesis de apertura, lo añadimos a la pila
            push(pila, crearNodo(infija[i]));
        } else if(infija[i] == ')') {
            // Si el carácter es un paréntesis de cierre, sacamos todos los operadores de la pila hasta encontrar un paréntesis de apertura
            while(peek(pila)->dato != '(') {
                postfija[j++] = pop(pila)->dato;
            }
            pop(pila);  // Eliminamos el paréntesis de apertura de la pila
        }
    }
    // Después de recorrer toda la expresión infija, sacamos todos los operadores restantes de la pila y los añadimos a la expresión postfija
    while(!estaVacia(pila)) {
        postfija[j++] = pop(pila)->dato;
    }
    // Añadimos el carácter nulo al final de la expresión postfija para indicar el final de la cadena
    postfija[j] = '\0';
}

// Función principal
int main() {
    // Definimos la expresión infija
    char infija[] = "(A+B)*C";
    // Creamos un array para almacenar la expresión postfija
    char postfija[10];
    // Convertimos la expresión infija a postfija
    infijaAPostfija(infija, postfija);
    // Imprimimos la expresión postfija
    printf("Postfija: %s\n", postfija);
    return 0;
}