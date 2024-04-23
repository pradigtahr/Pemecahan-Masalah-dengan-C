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

    /*Alokasi memori*/
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    /*Assign niai dari data*/
    one->data = 1111;
    two->data = 2222;
    three->data = 3333;

    /*Hubungkan node*/
    one->next = two;
    two->next = three;
    three->next = one;

    /*Simpan alamat dari node pertama ke dalam head*/
    head = one;

    /*Iterasi untuk menampilkan semua data pada linked list*/
    struct node *current = one;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != one);
    printf("\n");


    free(one);
    free(two);
    free(three);

    return 0;
}