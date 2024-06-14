#include <stdio.h>
#include <string.h>

int main() {
    int length;
    char stack[100], queue[100], inputChar;

    printf("Enter the length of the word\n");
    scanf("%d", &length);

    printf("Enter the word character by character\n");

    for (int i = 0; i < length; i++) {
        getchar();  // Consume the newline left-over
        scanf("%c", &inputChar);
        stack[i] = inputChar;
        queue[i] = inputChar;
    }

    int isPalindrome = 1;

    for (int i = 0; i < length; i++) {
        if (stack[length - 1 - i] != queue[i]) {
            isPalindrome = 0;
        }
    }

    if (isPalindrome) {
        printf("The word is a palindrome\n");
    } else {
        printf("The word is not a palindrome\n");
    }

    return 0;
}