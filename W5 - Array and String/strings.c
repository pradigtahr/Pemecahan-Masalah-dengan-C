#include <stdio.h>

int main(void){

    printf("***%8s***%3s***\n\n", "Short", "Strings");
    printf("\n%-20s\n", "George Washington");
    printf("%-20s\n", "John Adams");
    printf("%-20s\n", "Thomas Jefferson");
    printf("%-20s\n\n", "James Madison");

    //whitespace skipped
    char string1[20], string2[20];
    scanf("%s%s", string1, string2);
    printf("String inputted: %s %s\n\n", string1, string2);

    char dept[10], days[10];
    int course_num, time;
    scanf("%s%d%s%d", dept, &course_num, days, &time);
    printf("Department: %s", dept);
    printf("\nCourse Code: %d", course_num);
    printf("\nDays remaining: %s", days);
    printf("\nTime (hours): %d", time);

    return 0;
}