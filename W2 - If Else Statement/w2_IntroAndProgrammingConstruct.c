// Converts distances from miles to kilometers

// Preprocessor directive
#include <stdio.h>         /*printf, scanf definitions*/
#define KMS_PER_MILE 1.609 /*conversion constant*/

// Main function
int main(void)
{
    /*Distance in miles and the equivalent distance in kilometers.*/
    double miles, kms;

    /*Get the distance in miles.*/
    printf("Enter the distance in miles> ");
    scanf("%lf", &miles);

    /*Convert the distance to kilometers*/
    kms = KMS_PER_MILE * miles;

    /*Display the distance in kilometers*/
    printf("That equals %f kilometers. \n", kms);

    return (0);
}
