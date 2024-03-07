#include <stdio.h>
#include <string.h>

int main(void){

    // char str1[20];
    // strcpy(str1, "Avengers, assemble!");
    // printf("%s\n\n", str1);

    // char str2[20];
    // strncpy(str2, "Such a long string", 5);
    // printf("%s\n\n", str2);

    // Substrings
    char result[10], sl[15] = "Jan. 30, 1996";
    strncpy(result, &sl[0], 3);
    result[3] = '\0';
    printf("Result: %s\n\n", result);

    // Substring example
    /*char last[20], first[20], middle[20];
    char pres[20] = "Adams, John Quincy";
    strncpy(last, pres, 5);
    last[5] = '\0';
    strncpy(first, &pres[7], 4);
    first[4] = '\0';
    strncpy(middle, &pres[12], 12);
    middle[12] = '\0';
    printf("First name: %s\nMiddle name: %s\nLast name: %s\n\n", first, middle, last);
    */

    // Other way to extracting substring -> strtok
    char *last, *first, *middle;
    char pres[20] = "Adams, John Quincy";
    char presCopy[20];
    strcpy(presCopy, pres);
    last = strtok(presCopy, ", ");
    first = strtok(NULL, ", ");
    middle = strtok(NULL, ", ");
    printf("First name: %s\nMiddle name: %s\nLast name: %s\n\n", first, middle, last);
    



    return 0;
}