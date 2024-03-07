#include <stdio.h>
#include <string.h>

int main(){

    char    str1[20] = "Joyful",
            str2[20] = "Joyous";

    printf("Is A > B in ASCII code? %d\n", strcmp("B", "A"));
    printf("Comparing the first 3 char resulting in: %d\n", strncmp(str1, str2, 3));
    printf("Comparing the first 4 char resulting in: %d", strncmp(str1, str2, 4));

    return 0;
}