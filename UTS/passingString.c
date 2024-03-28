#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation
#include <string.h>
#define BUFFER_SIZE 1000

// Function to input the number of rows
int inputRows() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    return rows;
}

void getChoice(int *choice){
    printf("Choose the Option to edit the file:\n1. Add Row\n2. Delete Row\n3. Exit\n");
    printf(">> ");
    scanf("%d", choice);
    getchar(); // Consume newline character from input buffer
}

// Function to input strings into a 2D array
char** inputStrings(int rows) {
    char **strings = (char **)malloc(rows * sizeof(char *));
    if (strings == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        strings[i] = (char *)malloc(100 * sizeof(char)); // Assuming max string length is 100
        if (strings[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        printf("Enter string for row %d: ", i+1);
        scanf(" %99[^\n]", strings[i]);
    }

    return strings;
}

// Function to write all the strings
void writeStrings(char **strings, int rows) {
    FILE *fp;
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        fprintf(fp, "%s\n", strings[i]);
    }

    fclose(fp);

    printf("Strings written to file successfully.\n\n");

    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(strings[i]);
    }
    free(strings);
}

void deleteRow(const char *filename){
    // Declaration of row to delete
    int rowToDelete;
    printf("Enter the row to delete: ");
    scanf("%d", &rowToDelete);

    FILE *originalFile, *tempFile;
    char line[BUFFER_SIZE];
    int row = 0;

    originalFile = fopen(filename, "r");
    if(originalFile == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL){
        printf("Error creating temporary file\n");
        fclose(originalFile);
        exit(1);
    }

    // Read each line from original file
    while (fgets(line, sizeof(line), originalFile) != NULL){
        row++;

        // Skip the line to be deleted
        if(row != rowToDelete){
            fputs(line, tempFile);
        }
    }

    fclose(originalFile);
    fclose(tempFile);

    // Remove original file
    remove(filename);

    // Rename temporary file
    if (rename("temp.txt", filename) != 0){
        printf("Error renaming file\n");
        exit(1);
    }

    printf("Row %d deleted succesfully.\n", rowToDelete);
}

void addRow(const char *filename){
    FILE *file = fopen(filename, "a"); // Open file for appending
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char data[1000];
    printf("Enter data to be added to the file: ");
    fgets(data, sizeof(data), stdin);

    // Write the new row data
    fprintf(file, "%s\n", data);

    fclose(file);

    printf("Row added successfully.\n");
}


int main() {
    int rows;

    // Getting the number of rows from the user
    rows = inputRows();

    // Inputting strings into the 2D array
    char **strings = inputStrings(rows);

    // Passing the 2D array of strings to the function for processing
    writeStrings(strings, rows);

    int choice;

    // get and execute the choice
    do
    {
        getChoice(&choice);
        if (choice == 1){
        addRow("output.txt");
        }
        else if (choice == 2){
            deleteRow("output.txt");
        }
        else if (choice == 3){
            printf("exit the code.");
            return 0;
        }
        else{
            printf("Please input the valid value of choice!\n");
        }
    } while (choice != 3);
    

    return 0;
}
