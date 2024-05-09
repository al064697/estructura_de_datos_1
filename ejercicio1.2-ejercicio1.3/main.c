#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Función para verificar si una palabra es un palíndromo
bool isPalindrome(char word[]) {
    int left = 0;
    int right = strlen(word) - 1;

    // Recorremos la palabra desde ambos extremos hacia el centro
    while (left < right) {
        // Ignoramos los caracteres que no son letras
        while (!isalpha(word[left])) {
            left++;
        }
        while (!isalpha(word[right])) {
            right--;
        }

        // Convertimos ambas letras a minúsculas para la comparación
        char leftChar = tolower(word[left]);
        char rightChar = tolower(word[right]);

        // Si las letras son diferentes, no es un palíndromo
        if (leftChar != rightChar) {
            return false;
        }

        // Avanzamos hacia el centro
        left++;
        right--;
    }
    // Si llegamos aquí, todas las letras coincidieron, por lo que es un palíndromo
    return true;
}

int main() {
    char word[100];
    printf("Ingrese una palabra: ");
    fgets(word, 100, stdin);
    word[strcspn(word, "\n")] = '\0'; // Eliminar el carácter de nueva línea

    if (isPalindrome(word)) {
        printf("La palabra es un palíndromo.\n");
    } else {
        printf("La palabra no es un palíndromo.\n");
    }

    return 0;
}
