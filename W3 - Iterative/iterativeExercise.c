#include <stdio.h>
#define GRAV_CONST 10
#define COS_VAL 0.87
#define SIN_VAL 0.5
#define TIME_DELTA 0.001


/* Function Prototypes */
double distance(int init_velo);
double height(int init_velo);

/* Main function */
int main(void)
{
    /* Variable declaration */
    double  v_0, v_y, v_x,
            x,
            y,
            t;

    /* Enter the initial value of velocity */
    printf("Enter the initial velocity (m/s):\t");
    scanf("%lf", &v_0);

    /* Enter initial value of position (in x and y) and time */
    x = 0;
    y = 0;
    t = 0;

    /* initial velocity value with respect to x and y coordinates */
    v_y = v_0 * SIN_VAL;
    v_x = v_0 * COS_VAL;

    /* Display the table */
    printf("x\t\ty\t\tt");

    /* Iterative */
    do
    {
        v_y -= GRAV_CONST * TIME_DELTA;
        x += v_x * TIME_DELTA;
        y += v_y * TIME_DELTA - 0.5 * GRAV_CONST * TIME_DELTA;
        t += TIME_DELTA;
        printf("%.3f\t\t%.3f\t\t%.3f");
    } while (y>0);


    return 0;
}