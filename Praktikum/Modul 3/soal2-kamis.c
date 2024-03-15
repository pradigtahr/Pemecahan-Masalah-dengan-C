#include <stdio.h>
#include <string.h>
#define MAX_STRING 255
#define MAX_LINES 100 // Maximum number of lines

void displayMenu(void){
    printf("Welcome to The Millennium Falcon Archive System\n");
}

void validateUser(char username[MAX_STRING], int *value){
    char validUser[6][MAX_STRING] = {"kenobi", "r2d2", "c3po", "skywalker", "solo", "bacca"};

    printf("Access code: ");
    scanf("%s", username);

    *value = 0;
    for (int i = 0; i < 6; i++){
        if (strcmp(username, validUser[i]) == 0){
            *value = 1;
            break;
        }
    }
}

int main(void){

    char user[MAX_STRING];
    int isUserValid;
    char buffer[MAX_STRING];
    char lines[MAX_LINES][MAX_STRING]; // Array to store lines
    int line_count = 0;

    char *cypher_code, *translate;
    char message[MAX_STRING];

    // Display main menu
    displayMenu();

    // Get username and validate
    validateUser(user, &isUserValid);
    if (!isUserValid){
        printf("ACCESS DENIED\n");
        printf("ALERT ALERT ALERT\n");
        return 1; // Terminate the program if user validation fails
    }

    // Get filename and validate
    FILE *filePointer;
    char filename[MAX_STRING];

    printf("Input the desired filename: ");
    scanf("%s", filename);

    // Open file with read mode
    filePointer = fopen(filename, "r");

    // Check if the file exists
    if (filePointer == NULL){
        printf("File not found.\n");
        return 1; // Terminate the program if file does not exist
    }

    // Access each line of the file
    while(fgets(buffer, sizeof(buffer), filePointer) != NULL && line_count < MAX_LINES){
        // Hapus karakter newline pada file
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n'){
            buffer[len-1] = '\0';
        }
        // Salin string
        strcpy(lines[line_count], buffer);
        line_count++;
    }

    cypher_code = strtok(lines[0], ",");
    printf("%s", cypher_code);



    // Print the lines
    // for (int i = 0; i < line_count; i++){
    //     printf("%s\n", lines[i]);
    // }

    // Close the file
    fclose(filePointer);

    return 0;
}
