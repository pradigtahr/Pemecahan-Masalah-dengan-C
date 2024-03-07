#include <stdio.h>
#include <string.h>
#define STR_SIZE 15
#define STR_SIZE_2 20
#define STRSIZ 20

int main(void){

    // String concatenation -> strcat & strncat
    char f1[STR_SIZE] = "John ", f2[STR_SIZE] = "Jacqueline ", last[STR_SIZE] = "Kennedy";
    strcat(f1, last);
    // strcat(f2, last); -> error message
    strncat(f2, last, 3);
    printf("Name1: %s", f1);
    printf("\nName2: %s\n\n", f2);

    // Another example, with strlen()
    char    s1[STR_SIZE_2] = "Jupiter ",
            s2[STR_SIZE_2] = "LONGLONGSTRINGGGGG";
    
    // printf("%d ", strlen(s1));
    // printf("%d\n", strlen(strcat(s1, s2)));
    // printf("Concatenated Strings: %s\n\n", s1);

    // Example 2
    if (strlen(s1)+strlen(s2) < STRSIZ){
        strcat(s1, s2);
    }
    else{
        strncat(s1, s2, STRSIZ - strlen(s1) - 1);
        s1[STRSIZ-1] = '\0';
    }

    printf("%s", s1);

    return 0;
}