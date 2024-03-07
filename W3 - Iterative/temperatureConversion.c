/* Conversion of celsius to fahrenheit temperatures */
#include <stdio.h>

/* Constant macros */
#define CBEGIN 10
#define CLIMIT -5
#define CSTEP 5

int main(void)
{
    /* Variable declaration */
    int celsius;
    double fahrenheit;

    /* Display the table heading */
    printf(" Celsius Faherenheit\n");

    /* Display the table */
    for (celsius = CBEGIN; celsius >= CLIMIT; celsius -= CSTEP)
    {
        /* Table of values */
        fahrenheit = (1.8 * celsius) + 32.0;
        printf("%3c%3d%4c%7.2f\n", ' ', celsius, ' ', fahrenheit);
    }

    return 0;
}
