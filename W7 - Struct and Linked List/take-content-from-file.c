#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each node in the linked list
struct Node {
    char name[20];
    int score;
    int status;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char name[], int score, int status) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->status = status;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, char name[], int score, int status) {
    struct Node* newNode = createNode(name, score, status);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Nama: %s,\tSkor: %d,\tCabang: %d\n", temp->name, temp->score, temp->status);
        temp = temp->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    FILE *file = fopen("1.txt", "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }

    struct Node* head = NULL;
    char name[20];
    int score, status;

    // Read data from file and insert into linked list
    while (fscanf(file, "%19[^,],%d,%d\n", name, &score, &status) == 3) {
        insertNode(&head, name, score, status);
    }

    fclose(file);

    // Print the linked list
    printList(head);

    // Free memory allocated for the linked list
    freeList(head);

    return 0;
}
