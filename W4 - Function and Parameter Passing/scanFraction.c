#include <stdio.h>

void scan_fraction(int *nump, int *denomp)
{
    char slash;
    int status;
    int error;
    char discard;

    do {
        error = 0;  // Reset error flag for each attempt
        printf("Enter a common fraction as two integers separated by a slash: ");
        
        status = scanf("%d %c %d", nump, &slash, denomp);

        if (status < 3 || slash != '/' || *denomp <= 0) {
            error = 1;
            printf("Invalid input - ");
            
            if (status < 3) {
                printf("Please provide two integers separated by a slash.\n");
            } else if (slash != '/') {
                printf("Separate numerator and denominator by a slash (/).\n");
            } else {
                printf("Denominator must be a positive integer.\n");
            }

            // Discard extra input characters
            do {
                scanf("%c", &discard);
            } while (discard != '\n');
        }

    } while (error);
}

int main(void)
{
    int numerator, denominator;

    scan_fraction(&numerator, &denominator);

    printf("You entered the fraction: %d / %d\n", numerator, denominator);

    return 0;
}
