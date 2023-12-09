#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the size of the array of pointers
    int rows = 3;
    int cols = 4;

    // Declare an array of pointers
    int **arrayOfPointers;

    // Allocate memory for the array of pointers
    arrayOfPointers = (int **)malloc(rows * sizeof(int *));

    // Allocate memory for each individual array pointed to by the pointers
    for (int i = 0; i < rows; ++i) {
        arrayOfPointers[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the elements of the arrays
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arrayOfPointers[i][j] = i * cols + j;
        }
    }

    // Access and print the elements
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", arrayOfPointers[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory for each individual array
    for (int i = 0; i < rows; ++i) {
        free(arrayOfPointers[i]);
    }

    // Deallocate memory for the array of pointers
    free(arrayOfPointers);

    return 0;
}
