#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a character
typedef struct Character {
    char name[50];
    char type[50];
    struct Character* next;
} Character;

// Function prototypes
Character* createCharacter(char* name, char* type);
void appendCharacter(Character** head, char* name, char* type);
int determineWinner(char* type1, char* type2);
void printBattle(int round, char* name1, char* type1, char* name2, char* type2, int result);
void freeCharacters(Character* head);

int main() {
    // Open the input file
    FILE *file = fopen("pertarungan1.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Variables to store team information
    int numMembersA, numMembersB;
    char name[50], type[50], team;
    int round = 1;
    int scoreA = 0, scoreB = 0;

    // Linked lists to store characters for each team
    Character* teamA = NULL;
    Character* teamB = NULL;

    // Read the number of members for each team
    fscanf(file, "%d,%d,\n", &numMembersA, &numMembersB);

    // Start the battle
    printf("---Pertarungan antara tim A dan tim B dimulai!---\n");

    // Read characters and add them to the linked lists
    while (fscanf(file, "%[^,],%[^,],%c,\n", name, type, &team) == 3) {
    
        if (team == 'A') {
            appendCharacter(&teamA, name, type);
        } else if (team == 'B') {
            appendCharacter(&teamB, name, type);
        }
    }

    // Close the file
    fclose(file);

    // Fight until all rounds are completed
    Character* currentA = teamA;
    Character* currentB = teamB;

    while (currentA != NULL || currentB != NULL) {
        // Get the names and types of the characters for this round
        char name1[50], type1[50];
        char name2[50], type2[50];

        if (currentA != NULL) {
            strcpy(name1, currentA->name);
            strcpy(type1, currentA->type);
            currentA = currentA->next;
        }

        if (currentB != NULL) {
            strcpy(name2, currentB->name);
            strcpy(type2, currentB->type);
            currentB = currentB->next;
        }

        // Determine the winner of the battle
        int result = determineWinner(type1, type2);

        // Print the battle result
        printBattle(round, name1, type1, name2, type2, result);

        // Update scores
        if (result == 1) {
            scoreA++;
        } else if (result == -1) {
            scoreB++;
        }

        // Move to the next round
        round++;
    }

    // Print final scores
    printf("Skor akhir tim A = %d dan skor akhir tim B = %d\n", scoreA, scoreB);

    // Determine the winner of the match
    if (scoreA > scoreB) {
        printf("---Tim A berhasil memenangkan pertarungan dan menguasai galaksi setarel---\n");
    } else if (scoreA < scoreB) {
        printf("---Tim B berhasil memenangkan pertarungan dan menguasai galaksi setarel---\n");
    } else {
        printf("---Pertarungan berakhir imbang---\n");
    }

    // Free memory allocated for characters
    freeCharacters(teamA);
    freeCharacters(teamB);

    return 0;
}

// Function to create a new character node
Character* createCharacter(char* name, char* type) {
    Character* newCharacter = (Character*)malloc(sizeof(Character));
    if (newCharacter == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newCharacter->name, name);
    strcpy(newCharacter->type, type);
    newCharacter->next = NULL;
    return newCharacter;
}

// Function to append a character to the end of the linked list
void appendCharacter(Character** head, char* name, char* type) {
    Character* newCharacter = createCharacter(name, type);
    if (*head == NULL) {
        *head = newCharacter;
    } else {
        Character* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCharacter;
    }
}

// Function to determine the winner of the battle
int determineWinner(char* type1, char* type2) {
    // Implement the battle rules
    if (strcmp(type1, "Abundance") == 0) {
        if (strcmp(type2, "Erudition") == 0) return 1;
        else if (strcmp(type2, "Hunt") == 0) return -1;
    } else if (strcmp(type1, "Erudition") == 0) {
        if (strcmp(type2, "Nihility") == 0) return 1;
        else if (strcmp(type2, "Abundance") == 0) return -1;
    } else if (strcmp(type1, "Nihility") == 0) {
        if (strcmp(type2, "Harmony") == 0) return 1;
        else if (strcmp(type2, "Erudition") == 0) return -1;
    } else if (strcmp(type1, "Harmony") == 0) {
        if (strcmp(type2, "Destruction") == 0) return 1;
        else if (strcmp(type2, "Nihility") == 0) return -1;
    } else if (strcmp(type1, "Destruction") == 0) {
        if (strcmp(type2, "Preservation") == 0) return 1;
        else if (strcmp(type2, "Harmony") == 0) return -1;
    } else if (strcmp(type1, "Preservation") == 0) {
        if (strcmp(type2, "Hunt") == 0) return 1;
        else if (strcmp(type2, "Destruction") == 0) return -1;
    } else if (strcmp(type1, "Hunt") == 0) {
        if (strcmp(type2, "Abundance") == 0) return 1;
        else if (strcmp(type2, "Preservation") == 0) return -1;
    }

    // If none of the conditions are met, it's a draw
    return 0;
}

// Function to print the battle result
void printBattle(int round, char* name1, char* type1, char* name2, char* type2, int result) {
    printf("Babak %d | A - %s (%s) vs B - %s (%s) | ", round, name1, type1, name2, type2);
    if (result == 1) {
        printf("Tim A Menang (+1 poin)\n");
    } else if (result == -1) {
        printf("Tim B Menang (+1 poin)\n");
    } else {
        printf("Seri\n");
    }
}

// Function to free memory allocated for characters
void freeCharacters(Character* head) {
    while (head != NULL) {
        Character* temp = head;
        head = head->next;
        free(temp);
    }
}
