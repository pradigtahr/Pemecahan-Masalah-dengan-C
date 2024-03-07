#include <stdio.h>
#include <string.h>



int main(){

    // char line[80];
    // printf("Type in a line of data.\n");
    // gets(line);
    // printf("You typed: %s", line);
    // >> There is an error message

    char line[20];
    printf("Type in a line of data.\n");
    fgets(line, sizeof(line), stdin);
    printf("You typed: %s", line);
    


    return 0;
}