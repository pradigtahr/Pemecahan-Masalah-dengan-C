// Linked list implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creating a node
struct node {
    int value;
    char nama[255]; 
    struct node *next;
};

// print the linked list value
void printLinkedlist(struct node *p) {
    while (p != NULL) {
        printf("%d. %s\n", p->value, p->nama);
        p = p->next;
    }
}

int main() {
    // Initialize nodes
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    // Allocate memory
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    // Assign value values
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Assign nama values
    strcpy(one->nama, "Gastya");
    strcpy(two->nama, "Digta");
    strcpy(three->nama, "Zaki");

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    // printing node-value
    head = one;
    printLinkedlist(head);
}