#include <stdio.h>
#define PHI 3.14

void getAreaPerimeter(double r, double *area, double *perimeter)
{
    *area = PHI * r * r;
    *perimeter = 2 * PHI * r;
}


int main(void)
{
    double rad, area, perimeter;

    // Get r value from user
    printf("Enter radius of circle:\t");
    scanf("%lf", &rad);

    //get area and perimeter
    getAreaPerimeter(rad, &area, &perimeter);

    //print result
    printf("Area: %.3f\nPerimeter: %.3f", area, perimeter);

    return 0;
}