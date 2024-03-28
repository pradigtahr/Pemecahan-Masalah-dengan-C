#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wombat {
    float f;
    long int L;
    struct wombat *Next;
    char Name[20];
};

// Function to print the linked list
void printLinkedList(struct wombat *head) {
    struct wombat *current = head;

    printf("Linked List:\n");
    while (current != NULL) {
        printf("Name: %s\n", current->Name);
        printf("Float: %f\n", current->f);
        printf("Long Int: %ld\n", current->L);
        printf("\n");
        current = current->Next;
    }
}

int main(void){
    struct wombat Ralph;
    struct wombat Munroe[10];

    // Set Ralph's float and name field
    Ralph.f = 13.7;
    strcpy(Ralph.Name, "The Doctor");
    printf("Ralph %s.\n", Ralph.Name);

    // Declare a ten element linked list of Wombats. Make sure that you link them together.
    struct wombat A = {0, 0, NULL, "Digta"};
    struct wombat B = {0, 0, &A, "Digta1"};
    struct wombat C = {0, 0, &B, "Digta2"};
    struct wombat D = {0, 0, &C, "Digta3"};
    struct wombat E = {0, 0, &D, "Digta4"};
    struct wombat F = {0, 0, &E, "Digta5"};
    struct wombat G = {0, 0, &F, "Digta6"};
    struct wombat H = {0, 0, &G, "Digta7"};
    struct wombat I = {0, 0, &H, "Digta8"};
    struct wombat J = {0, 0, &I, "Digta9"};

    // Print the linked list
    printLinkedList(&B);

    return 0;
}
