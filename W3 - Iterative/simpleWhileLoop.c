#include <stdio.h>

int main(void)
{
    int counter, howmuch;

    scanf("%d", &howmuch);
    counter = 0;
    while (counter < howmuch)
    {
        counter++;
        printf("Loop number: %d\n", counter);
    }
    return 0;
}