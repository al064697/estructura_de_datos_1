#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    cout << "Enter the number of characters in the word (max 8): ";
    int length;
    cin >> length;
    cin.ignore(); // Consumir el salto de línea pendiente

    if (length > 6) {
        cout << " The word exceeds 8." << endl;
        return 0;
    }

    char stack[8];
    char queue[8];
    int top = -1;
    int rear = -1;

    cout << "Enter the word character by character:" << endl;
    string word;
    for (int i = 0; i < length; i++) {
        cout << "Character " << (i + 1) << ": ";
        char letter;
        cin >> letter;
        word.push_back(letter);

        // Llenar la pila y la cola
        stack[++top] = letter;
        queue[++rear] = letter;
    }

    // Verificar si es palíndromo
    bool isPalindrome = true;
    int tempTop = top;
    for (int i = 0; i <= top; i++) {
        if (stack[tempTop--] != queue[i]) {
            isPalindrome = false;
            break;
        }
    }

    // Imprimir pila y cola
    cout << "Stack: " << endl;
    for (int i = 0; i <= top; i++) {
        cout << "[" << stack[i] << "]" << "  TOP= " << i << endl;
    }
    cout << "\nQueue:";
    for (int i = 0; i <= rear; i++) {
        cout << "[" << queue[i] << "]";
    }

    // Imprimir resultado
    if (isPalindrome) {
        cout << "\nThe entered word is a palindrome." << endl;
    } else {
        cout << "\nThe entered word is NOT a palindrome." << endl;
    }

    return 0;
}
