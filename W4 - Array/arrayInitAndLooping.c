/* Array Initialization and Looping:
1. Declare an array 'grades' to store 5 student grades.
2. Initialize the array with values entered by the user using a loop.
3. Calculate and print the average grade. */

#include <stdio.h>
#define ARRAY_SIZE 5

double getAverage(int arr[], int n)
{
    // Variable to save the sum up grades
    int sum = 0;
    /* Update sum value */
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    /* Get the average */
    return (double)sum / n;
}

void getArray(int grades[], int n)
{
    /* Filling the array's value by users */
    for (int i = 0; i < n; i++)
    {
        printf("Enter grade value number %d:\t", i + 1);
        scanf("%d", &grades[i]);
    }
}

int main(void)
{
    int arrGrades[ARRAY_SIZE];
    double avgGrades;

    /* Get the array */
    getArray(arrGrades, ARRAY_SIZE);

    /* Calculates the average result */
    avgGrades = getAverage(arrGrades, ARRAY_SIZE);

    /* Display the result */
    printf("The average value of array of grades is: %.2f", avgGrades);

    return 0;
}