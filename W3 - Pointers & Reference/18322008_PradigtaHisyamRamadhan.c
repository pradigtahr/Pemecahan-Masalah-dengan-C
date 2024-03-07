#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUG 1

void generateMatrix(int min_rand, int max_rand, int cube[5][5][5]) {
    /* Seed the random number generator with the current time */
    srand(time(NULL));

    /* Fill the matrix with a loop */
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                /* Generate random value within the range min_rand to max_rand */
                cube[i][j][k] = (rand() / (double)RAND_MAX) * (max_rand - min_rand + 1) + min_rand;
            }
        }
    }
}

void swapValues(int (*matrix)[5][5][5], int x1, int y1, int z1, int x2, int y2, int z2) {
    // Ensure that the coordinates are within the valid range (0 to 4)
    if (x1 >= 0 && x1 < 5 && y1 >= 0 && y1 < 5 && z1 >= 0 && z1 < 5 &&
        x2 >= 0 && x2 < 5 && y2 >= 0 && y2 < 5 && z2 >= 0 && z2 < 5) {

        // Swap values at the specified coordinates
        int temp = (*matrix)[x1][y1][z1];
        (*matrix)[x1][y1][z1] = (*matrix)[x2][y2][z2];
        (*matrix)[x2][y2][z2] = temp;
    } else {
        // Handle invalid coordinates
        printf("Invalid coordinates.\n");
    }
}

void displayMatrix(int matrix[5][5][5]){
    printf("Matrix generated:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                printf("%d\t", matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main(void) {
    /* Declaration of a 3D array representing a 5x5x5 cube */
    int cube[5][5][5],
        min_rand,
        max_rand;

    /* User sets the minimum and maximum range of the random value */
    printf("Enter the minimum value of random number:\t");
    scanf("%d", &min_rand);
    printf("Enter the maximum value of random number:\t");
    scanf("%d", &max_rand);

    /* Call the function to generate the matrix */
    generateMatrix(min_rand, max_rand, cube);

    printf("Matrix before replacement:\n");
    displayMatrix(cube);

    // Perform swaps based on the provided coordinates
    swapValues(&cube, 0, 4, 0, 4, 0, 4);
    swapValues(&cube, 0, 4, 1, 4, 0, 3);
    swapValues(&cube, 0, 4, 2, 4, 0, 2);
    swapValues(&cube, 1, 4, 0, 3, 0, 4);
    swapValues(&cube, 1, 4, 1, 3, 0, 3);
    swapValues(&cube, 2, 4, 0, 2, 0, 4);

    printf("Matrix after replacement:\n");
    displayMatrix(cube);
    
    return 0;
}
