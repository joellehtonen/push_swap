#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define RANGE 1000 // Range of random numbers

bool isUnique(int num, int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == num)
            return false;
    }
    return true;
}

int main() {
    int max_num;

    printf("Enter the number of random numbers you want to generate: ");
    scanf("%d", &max_num);

    if (max_num <= 0) {
        printf("Please enter a positive number greater than 0.\n");
        return 1;
    }

    int *generated = (int *)malloc(max_num * sizeof(int)); // Array to store generated numbers
    if (generated == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator

    int count = 0;
    while (count < max_num) {
        int num = rand() % RANGE; // Generate a random number

        // Check if the number is unique
        if (isUnique(num, generated, count)) {
            generated[count] = num;
            count++;
        }
    }

    // Print the generated unique numbers
    printf("Unique random numbers:\n");
    for (int i = 0; i < max_num; i++) {
        printf("%d ", generated[i]);
    }
    printf("\n");

    free(generated); // Free allocated memory

    return 0;
}
