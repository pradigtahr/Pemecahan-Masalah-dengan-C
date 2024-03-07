#include <stdio.h>
#define SENTINEL 0
#define NUM_MONTHS 12

int main(void)
{
    int month,     /* number of month being processed */
        mem_sight, /* one member's sightings for this month */
        sightings; /* total sightings so far for this month */

    printf("BALD EAGLE SIGHTINGS\n");

    /* Outer for loop */
    for (month = 1; month <= NUM_MONTHS; ++month)
    {
        sightings = 0;

        /* Prompt for input inside the outer loop */
        printf("Enter sightings for month %d (0 to end): ", month);

        /* Inner while loop */
        scanf("%d", &mem_sight);            // Update: declare the loop control variable
        while (mem_sight != SENTINEL)
        {
            if (mem_sight >= 0)
            {
                sightings += mem_sight;
            }
            else
            {
                printf("WARNING!\nNegative count %d ignored\n", mem_sight);
            }

            /* Update mem_sight inside the loop */
            printf("Enter sightings for month %d (0 to end): ", month);
            scanf("%d", &mem_sight);
        }

        printf("Month %2d: %2d\n", month, sightings);
    }

    return 0;
}
