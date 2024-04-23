#include <stdio.h>

int main() {
    FILE* ptr = fopen("abc.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }

    // Read and discard the first line
    char first_line[100];
    fgets(first_line, sizeof(first_line), ptr);

    char name[100], age[100], city[100];
    // Adjusted fscanf format specifier
    while (fscanf(ptr, "%s %s %s", name, age, city) == 3) // == 3 sesuai jumlah buffer
        printf("Name: %s\tAge: %s\tCity: %s\n", name, age, city);

    fclose(ptr); // Don't forget to close the file
    return 0;
}
