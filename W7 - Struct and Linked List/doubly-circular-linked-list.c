#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev; // Add a pointer to the previous node
};

int main(void){

    /* Inisialisasi node */
    struct node *head = NULL;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    /* Alokasi memori */
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    /* Assign nilai dari data */
    one->data = 1111;
    two->data = 2222;
    three->data = 3333;

    /* Hubungkan node */
    one->next = two;
    two->next = three;
    three->next = one;

    one->prev = three; // Hubungkan node terakhir dengan node pertama
    two->prev = one;
    three->prev = two;

    /* Simpan alamat dari node pertama ke dalam head */
    head = one;

    /* Iterasi untuk menampilkan semua data pada linked list */
    struct node *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");

    free(one);
    free(two);
    free(three);

    return 0;
}
