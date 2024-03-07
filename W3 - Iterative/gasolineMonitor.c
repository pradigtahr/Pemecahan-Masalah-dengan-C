/*
 * Monitor gasoline supply in the storage tank.
 * Issue warning when supply falls below MIN_PCT % of tank capacity
 */

#include <stdio.h>

/* Constant macros */
#define CAPACITY 80000.0        // number of barrels tank can hold
#define MIN_PCT 10              // warn when supply falls below this percent of capacity
#define GALS_PER_BRL 42.0       // number of U.S. gallons one barrel

/* Function prototype */
double monitor_gas(double min_supply, double start_supply);

/* Main function */
int main(void)
{
    /* Variable declaration */
    double  start_supply,       // input - initial supply in barrels
            min_supply,         // minimum number of barrels left without warning
            current;            // output - current supply in barrels
    
    /* Compute minimum supply without warning */
    min_supply = (MIN_PCT / 100) * CAPACITY;

    /* Get initial supply */
    printf("Number of barrels currently in tank: ");
    scanf("%lf", &start_supply);

    /* Substract amounts removed and display amount remaining as long as minimum supply remains. */
    current = monitor_gas(min_supply, start_supply);

    /* Issue warning */
    printf("Only %.2f barrels are left.\n\n *** WARNING ***\nAvailable supply is less than %d percent of tank's.\n%.2f-barrel capacity.\n", current, MIN_PCT, CAPACITY);

    return 0;
}

/* 
 * Computes and display amount of gas remaining after each delivery.
 * Pre  : min_supply and start_supply are defined.
 * post : returns the supply available (in barrels) after all permitted removals.
 * The value returned is the first supply amount that is less than min_supply
 */

double monitor_gas(double min_supply, double start_supply)
{
    /* Local vaiable declaration */
    double  remov_gals,     // input - amount of current delivery
            remov_brls,     // in barrels and gallons
            current;        // output - current supply in barrels

    for (current = start_supply; current >= min_supply; current -= remov_brls)
    {
        /* Display current barrels */
        printf("%.2f barrels are availabe.\n\n", current);

        /* Take user's input to remove barrels (in gallons) */
        printf("Enter number of gallons removed: ");
        scanf("%lf", &remov_gals);

        /* Update the current by substracting it with remov_brls */
        remov_brls = remov_gals / GALS_PER_BRL;
        printf("After removal of %.2f gallons (%.2f barrels),\n", remov_gals, remov_brls);
    }

    return(current);
}