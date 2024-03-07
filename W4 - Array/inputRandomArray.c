/* Update, instead taking the input from users, the program will generate random numbers to fill the array's value. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputArray(int arr[], int n)
{
    /* Local variable */
    int lower_limit, upper_limit;
    
    /* Seed the random number generator with the current time */
    srand(time(NULL));

    /* Get the lower and upper value for the random number generated */
    printf("Enter the lower limit:\t");
    scanf("%d", &lower_limit);
    printf("Enter the upper limit:\t");
    scanf("%d", &upper_limit);

    for (int i = 0; i < n; i++)
    {
        // Generate and assign random numbers to the array
        arr[i] = (rand() / (double)RAND_MAX) * (upper_limit - lower_limit + 1) + lower_limit;
    }
}

void displayArray(int arr[], int n)
{
    /* Display array's value */
    printf("Entered array: [");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i == n - 1)
        { // Closes the bracket if i reached the last index
            printf("].");
        }
        else
        {
            printf(", "); // Add comma and space for elements other than the last one
        }
    }
    printf("\n");
}

int main(void)
{
    /* Declaring variable for array's size */
    int n;

    /* Get the size of the array from the user */
    printf("Enter the size of array: ");
    scanf("%d", &n);

    /* Declare an array of size 'n' */
    int arr[n];

    /* Call the function to input elements into the array */
    inputArray(arr, n);

    /* Call the function to display the entered array */
    displayArray(arr, n);

    return 0;
}