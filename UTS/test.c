#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

int main(void){
    // char *buffer = (char *)malloc(MAX_LEN * sizeof(char));
    char *buffer;
    printf("Masukkan tanggal lahir(DD/MM/YYYY): ");
    // scanf(" %99[^\n]", buffer);
    
    fgets(buffer, MAX_LEN, stdin);
    //Remove new line characters
    buffer[strcspn(buffer, "\n")] = '\0';


    printf("You inputted: %s\n\n", buffer);

    // Get char berdasarkan token
    char *date, *month, *year;
    date = strtok(buffer, "/");
    month = strtok(NULL, "/");
    year = strtok(NULL, "");

    // print tanggal lahir
    printf("Anda lahir pada tanggal %s bulan %s tahun %s.", date, month, year);

    return 0;
}
