#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 3
#define UPPER_LIMIT 10
#define LOWER_LIMIT 1

int main(void)
{
    /* Declare the 'matrix' variable */
    int matrix[MATRIX_SIZE][MATRIX_SIZE];

    /* Seed the random number generator with the current time */
    srand(time(NULL));

    /* Initialize the matrix with random values */
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            // Generate random integer values within the specified range
            matrix[i][j] = rand() % (UPPER_LIMIT - LOWER_LIMIT + 1) + LOWER_LIMIT;
        }
    }

    /* Print the matrix */
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            // Print the row
            printf("%d", matrix[i][j]);

            // Print tab unless it's the last element in the row
            if (j != MATRIX_SIZE - 1)
            {
                printf("\t");
            }
        }
        // Move to the next row
        printf("\n");
    }

    return 0;
}
