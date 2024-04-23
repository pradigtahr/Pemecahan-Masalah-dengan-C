#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    char nama[50];
    int nim;
    float ipk;
    struct Mahasiswa *next; // Pointer untuk mengakses alamat selanjutnya dari linked list
} Mahasiswa;

void hapusMahasiswa(Mahasiswa **head, int nim) {
    Mahasiswa *current = *head;
    Mahasiswa *prev = NULL;

    // Mencari node dengan NIM yang sesuai dengan input pengguna
    while (current != NULL && current->nim != nim) {
        prev = current;
        current = current->next;
    }

    // Apabila node dengan NIM tersebut ketemu
    if (current != NULL) {
        // Apabila node adalah head/elemen pertama linked list
        if (prev == NULL) {
            *head = current->next;
        } 
        // Apabila node yang dihapus bukan head
        else {
            prev->next = current->next;
        }
        // Bebaskan memori dari node yang dihapus
        free(current);
        printf("Mahasiswa dengan NIM %d berhasil dihapus!\n", nim);
    } 
    // Apabila node yang mengadung NIM yang dimasukan pengguna tida ada dalam liked list
    else {
        printf("Mahasiswa dengan NIM %d tidak ada!\n", nim);
    }
}

int main(void) {
    Mahasiswa *head = NULL;
    
    Mahasiswa *mahasiswa1 = malloc(sizeof(Mahasiswa));
    strcpy(mahasiswa1->nama, "John");
    mahasiswa1->nim = 12345;
    mahasiswa1->ipk = 3.75;
    mahasiswa1->next = NULL;
    head = mahasiswa1;

    Mahasiswa *mahasiswa2 = malloc(sizeof(Mahasiswa));
    strcpy(mahasiswa2->nama, "Alice");
    mahasiswa2->nim = 54321;
    mahasiswa2->ipk = 3.95;
    mahasiswa2->next = NULL;
    mahasiswa1->next = mahasiswa2;

    // Meminta masukan dari pengguna untuk menghapus mahasiswa yang akan dihapus berdasarkan NIM
    int hapusNIM;
    printf("Masukkan NIM mahasiswa yang ingin dihapus: ");
    scanf("%d", &hapusNIM);

    // Memanggil fungsi
    hapusMahasiswa(&head, hapusNIM);

    // Menampilkan data mahasiswa setelah menghapus data
    printf("Data Mahasiswa setelah penghapusan:\n");
    Mahasiswa *current = head;
    while (current != NULL) {
        printf("Nama: %s, NIM: %d, IPK: %.2f\n", current->nama, current->nim, current->ipk);
        current = current->next;
    }

    // Bebaskan memori
    current = head;
    while (current != NULL) {
        Mahasiswa *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

