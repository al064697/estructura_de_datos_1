#include <stdio.h>

int main() {
    int option = 0;
    int num_of_heights = -1;
    float heights[10] = {0.0};

    while (option == 0 && num_of_heights < 9) {
        printf("Do you want to add a person's height?\n");
        printf("1.- Yes\n");
        printf("2.- No\n");
        scanf("%d", &option);
        if (option == 1) {
            num_of_heights += 1;
            printf("Enter the height (in meters and with decimal point)\n");
            scanf("%f", &heights[num_of_heights]);

            // Insertion sort
            for (int i = 1; i <= num_of_heights; i++) {
                float key = heights[i];
                int j = i - 1;
                while (j >= 0 && heights[j] > key) {
                    heights[j + 1] = heights[j];
                    j = j - 1;
                }
                heights[j + 1] = key;
            }

            // Display heights
            printf("Current heights:\n");
            for (int i = 0; i <= num_of_heights; i++) {
                printf("%f\n", heights[i]);
            }
            printf("------\n");

            option = 0; // Reset option to allow adding more heights
        }
    }

    if (num_of_heights == 9) {
        printf("The maximum number of height records has been reached (10 heights)\n");
    }

    printf("The entered heights sorted from lowest to highest are:\n");
    for (int i = 0; i <= num_of_heights; i++) {
        printf("%f\n", heights[i]);
    }

    return 0;
}