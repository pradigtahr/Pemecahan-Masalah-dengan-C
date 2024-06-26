#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

int main(void){

    /*Inisialisasi node*/
    struct node*head;
    struct node*one = NULL;
    struct node*two = NULL;
    struct node*three = NULL;

    /*Alokasi memorii*/
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    /*Assign nilai tiap data*/
    one->data = 1111;
    two->data = 2222;
    three->data = 3333;

    /*Hubungkan node*/
    one->next = two;
    one->prev = NULL;

    two->next = three;
    two->prev = one;

    three->next = NULL;
    three->prev = two;

    /*Simpan alamat node pertama ke dalam head*/
    head = one;

    /*Iterasi untuk menampilkan semua data pada linked list*/
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