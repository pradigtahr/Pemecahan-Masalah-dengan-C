/* Reads serial number and displays class of ship */
#include <stdio.h>

int main(void)
{
    char class; // input - character indicating class of ship

    printf("Enter ship serial number>\t"); /* Read first character of serial number */
    scanf("%c", &class);                   /* Scan first letter */

    printf("Ship class is %c: ", class); /* Display first character followed by ship class */

    switch (class)
    {
    case 'B':
    case 'b':
        printf("Battleship\n");
        break;

    case 'C':
    case 'c':
        printf("Cruisers\n");
        break;

    case 'D':
    case 'd':
        printf("Destroyer\n");
        break;

    case 'F':
    case 'f':
        printf("Frigate\n");
        break;

    default:
        printf("Unknown\n");
    }
    return (0);
}