#include <stdio.h>
#include <math.h>

void separate(double num, char *signp, int *wholep, double *fracp)
{
    double magnitude;
    /*Determines sign of num*/
    if (num < 0){
        *signp = '-';
    } else if (num == 0){
        *signp = ' ';
    } else {
        *signp = '+';
    }

    /*Finds magnitude of num (its absolute value) and separates it into whole and fractional parts*/
    magnitude = fabs(num);
    *wholep = floor(magnitude);
    *fracp = magnitude - *wholep;
}

int main(void){
    double value;
    char sign;
    int whole;
    double fraction;

    /*Gets data*/
    printf("Enter a value to analyze:\t");
    scanf("%lf", &value);

    /*Separates data value into three parts*/
    separate(value, &sign, &whole, &fraction);

    /*Print results*/
    printf("Parts of %.4f\nSign: %c\nWhole Num: %d\nFraction: %.4f", value, sign, whole, fraction);

    return 0;
}