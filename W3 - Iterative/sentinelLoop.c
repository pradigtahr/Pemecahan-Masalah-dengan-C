/* Compute the sum of a list of exam scores. */
#include <stdio.h>
#define SENTINEL -99
#define DEBUG 0             // Update1 to determine bug

int main(void)
{
    int sum = 0,        // output - sum of scores input so far
        score;          // input - current score

    /* Accumulate sum of all scores, updated version of for loops, the first score obtained in the for loop. */
    printf("Enter first score (or %d to quit):\t", SENTINEL);
    for (scanf("%d", &score); score != SENTINEL; scanf("%d", &score))
    {
        sum += score;
        if (DEBUG)
        {
            printf("Score: %d\n", score);
            printf("Sum: %d\n\n", sum);
        }
        printf("Enter next score (or %d to quit):\t", SENTINEL);
    }

    return 0;
}