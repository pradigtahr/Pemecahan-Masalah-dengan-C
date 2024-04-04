#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(void){

    /*Inisialisasi node*/
    struct node*head;
    struct node*one = NULL;
    struct node*two = NULL;
    struct node*three = NULL;

    /*Alokasi memory*/
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    /*Assign data values*/
    one->data = 1111;
    two->data = 2222;
    three->data = 3333;

    /*assign data value*/
    one->next = two;
    two->next = three;
    three->next = NULL;

    /*Save address of first node in head*/
    head = one;

    /*Traverse the linked list and print each node's data*/
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    free(one);
    free(two);
    free(three);

    return 0;
}