#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

int main(void){
    // char *buffer = (char *)malloc(MAX_LEN * sizeof(char));
    char *buffer;
    printf("Enter a string: ");
    // scanf(" %99[^\n]", buffer);
    fgets(buffer, MAX_LEN, stdin);

    printf("You inputted: %s", buffer);





    return 0;
}
