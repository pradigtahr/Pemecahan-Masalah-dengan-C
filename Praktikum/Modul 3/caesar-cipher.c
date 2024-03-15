#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100 // Maximum number of lines
#define MAX_STRING 255 // Maximum length of each line

// Function to encrypt a string using Caesar cipher
void encrypt(char *str, int shift) {
    for (int i = 0; str[i] != '\0'; ++i) {
        // Encrypt only alphabetic characters
        if (isalpha(str[i])) {
            char base = isupper(str[i]) ? 'A' : 'a'; // Determine base ('A' or 'a')
            str[i] = ((str[i] - base + shift) % 26) + base; // Apply Caesar cipher
        }
    }
}

int main(void) {
    char lines[MAX_LINES][MAX_STRING]; // Array to store lines
    char buffer[MAX_STRING]; // Buffer for reading lines
    int line_count = 0; // Counter for lines read

    // Open the file
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read lines from the file and store them into the array
    while (fgets(buffer, sizeof(buffer), file) != NULL && line_count < MAX_LINES) {
        // Remove newline character from the end of the line
        buffer[strcspn(buffer, "\n")] = '\0';
        // Copy the line into the array
        strcpy(lines[line_count], buffer);
        // Encrypt the line
        encrypt(lines[line_count], 3); // Encrypt with a shift of 3
        // Increment line count
        line_count++;
    }

    // Close the file
    fclose(file);

    // Print the encrypted lines
    for (int i = 0; i < line_count; i++) {
        printf("Line %d (Encrypted): %s\n", i + 1, lines[i]);
    }

    return 0;
}
