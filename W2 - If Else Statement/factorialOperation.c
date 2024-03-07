/*
 * Computes n!
 * Pre: n is greater than or equal to zero
 */

#include <stdio.h>

/* Function prototype */
int factorial(int n);

int main(void)
{
    int n, product;

    printf("Enter number to operate> ");
    scanf("%d", &n);

    /* Compute the result */
    product = factorial(n);

    /* Display the result */
    printf("The result of %d! is %d.", n, product);

    return 0;
}

int factorial(int n)
{
    int i,       // Local variables
        product; // Accumulator for product computation
    product = 1;

    /* Computes the product: n x (n-1) x (n-2) x . . . x 2 x 1 */
    for (i = n; i > 1; --i)
    {
        product *= i;
    }

    /* Returns function result */
    return (product);
}