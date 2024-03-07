#include <stdio.h>

int main(void)
{
    /* Variable declaration */
    char road_status;
    double temp;

    /* User input */
    printf("Enter road status (if slick, type 'S')>\t");
    scanf(" %c", &road_status);

    printf("Enter temperature(in celcius)>\t");
    scanf(" %.2f", &temp);

    /*Warning if road is slick. If it's not, check the temperature to fill the other conditions*/
    if (road_status == 'S')
    {
        if (temp > 0)
        {
            printf("Wet roads ahead\nStopping time doubled.\n");
        }
        else
        {
            printf("Icy roads ahead\nStopping time quadrupled.\n");
        }
    }
    else
    {
        printf("Drive carefully!\n");
    }
}