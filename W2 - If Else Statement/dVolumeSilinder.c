#include <stdio.h>
#define PHI 3.14159

int main(void){
    int radius, height;
    double volume;

    printf("Enter the cylinder's radius > ");
    scanf("%d", &radius);

    printf("Enter the cylinder's height > ");
    scanf("%d", &height);

    volume = PHI * (radius * radius) * height;

    printf("The cylinder's volume is %.3f.", volume);

    return(0);
}
