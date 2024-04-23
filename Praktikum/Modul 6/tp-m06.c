#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa{
    char nama[50];
    int nim;
    float ipk;
    struct Mahasiswa *next; // Pointer ke node berikutnya dalam linked list
}Mahasiswa;

void tambahMahasiswa(Mahasiswa **head, char addNama[50], int addNim, float addIpk){
    // Alokasi memori untuk list baru
    Mahasiswa *mahasiswa_baru = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    if (mahasiswa_baru == NULL){
        printf("Alokasi memori gagal!\n");
        exit(1);
    }

    strcpy(mahasiswa_baru->nama, addNama);
    mahasiswa_baru->nim = addNim;
    mahasiswa_baru->ipk = addIpk;
    mahasiswa_baru->next = NULL;

    // Inisiasi data pada linked list apabila tidak ada head
    if(*head == NULL){
        *head = mahasiswa_baru;
    }
    // Apabila head sudah terisi
    else{
        Mahasiswa *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = mahasiswa_baru;
    }

}

void hapusMahasiswa(Mahasiswa **head, int nim){
    Mahasiswa *current = *head;
    Mahasiswa *prev = NULL;

    // mencari mahasiswa pada linked list berdasarkan nim yang diberikan
    while (current != NULL && current->nim != nim){
        prev = current;
        current = current->next;
    }

    // Apabila node ditemukan
    if (current != NULL){
        // Node yang dihapus adalah head
        if (prev == NULL){
            *head = current->next;
        }
        // Apabila node yang dihapus bukan head
        else{
            prev->next = current->next;
        }
        // bebaskan memori untuk node current
        free(current);
        printf("Mahasiswa dengan NIM %d berhasil dihapus!\n", nim);
    }
    else{
        printf("Mahasiswa dengan NIM %d tidak ada!\n", nim);
    }
}

void tampilkanMahasiswa(Mahasiswa *head){
    Mahasiswa *current = head;
    printf("Data mahasiswa Universitas B\n");
    while(current != NULL){
        printf("NIM: %d, Nama: %s, IPK: %.2f\n", current->nim, current->nama, current->ipk);
        current = current->next;
    }
}

int main(void){
    Mahasiswa *head = NULL;
    int opsi, nim;
    float ipk;
    char nama[50];

    do{
        printf("---------------------------------------------");
        printf("\nProgram Pendataan Mahasiswa Universitas B\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Hapus data mahasiswa berdasarkan NIM\n");
        printf("3. Tampilkan data mahasiswa\n");
        printf("4. Keluar program\n");
        printf("Masukkan menu yang ingin dipilih: ");
        scanf("%d", &opsi);

        switch(opsi){
        case 1:
            printf("---------------------------------------------\n");
            // Mendapatkan nama, nim, dan IPK mahasiswa
            printf("Masukkan nama mahasiswa: ");
            getchar();  // mengambil karakter newline dari input sebelumnya
            fgets(nama, 50, stdin);
            nama[strcspn(nama, "\n")] = '\0';

            printf("Masukkan NIM mahasiswa: ");
            scanf("%d", &nim);

            printf("Masukkan IPK mahasiswa (koma menggunakan titik): ");
            scanf("%f", &ipk);

            tambahMahasiswa(&head, nama, nim, ipk);
            break;
        
        case 2:
            printf("---------------------------------------------\n");
            // Mendapatkan NIM mahasiswa
            printf("Masukkan NIM mahasiswa yang ingin dihapus datanya: ");
            scanf("%d", &nim);

            hapusMahasiswa(&head, nim);
            break;
        case 3:
            printf("---------------------------------------------\n");
            tampilkanMahasiswa(head);
            break;
        case 4:
            printf("---------------------------------------------\n");
            printf("Keluar dari program.");
            break;
        default:
            printf("---------------------------------------------\n");
            printf("Silakan masukkan opsi menu diantara angka 1-4!\n");
            break;
        }

    } while (opsi != 4);
    

    return 0;
}