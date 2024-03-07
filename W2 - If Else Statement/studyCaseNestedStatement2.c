#include <stdio.h>

/* Function prototype */
void printMessage(char marital_status, char gender, int age);

int main(void)
{
    /* Variable declaration */
    char marital_status, gender;
    int age;

    /* Taking input from user */
    printf("Enter your marital status (S for single, M for married)>\t\t");
    scanf(" %c", &marital_status);

    printf("Enter your gender (M/F)>\t\t");
    scanf(" %c", &gender);

    printf("Enter your age>\t\t");
    scanf("%d", &age);

    /* Print message to users */
    printMessage(marital_status, gender, age);

    return 0;
}

/* Function declaration */
void printMessage(char marital_status, char gender, int age)
{
    /* Print a message if all criteria are met. */
    if (marital_status == 'S' && gender == 'M' && age >= 18 && age <= 26)
    {
        printf("All criteria are met.\n");
    }
}
