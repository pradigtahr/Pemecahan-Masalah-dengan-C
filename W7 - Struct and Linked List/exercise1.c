#include <stdio.h>
#include <stdlib.h>

struct Node{
    int age;
    int weight;
    struct Node* next;
};

// Insert at the beginning
// void insertAtBeginning()

// Insert node after a node
void insertAfter(struct Node* prev_node, int new_age, int new_weight){
    if (prev_node == NULL){
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->age = new_age;
    new_node->weight = new_weight;
    prev_node->next = new_node;
}


int main(void){
    struct Node* head = NULL;

    insertAfter(head->age, 3, 4);

    return 0;
}