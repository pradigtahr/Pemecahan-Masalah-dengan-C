/*EL2208 Praktikum Pemecahan Masalah dengan C 2023/2024
*TP Modul         : 5 - Structure & Dynamic Array
*Hari dan Tanggal : Senin, 1 April 2024 
*Nama (NIM)       : Pradigta Hisyam Ramadhan (18322008)
*Nama File        : tp-m05.c
*Deskripsi        : Program untuk melakukan implementasi autograder 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Membuat node
struct Praktikan{
    char *nama;
    int NIM;
    int pemilihanSoal;
    int test1;
    int test2;
    int test3;
    int test4;
    int test5;
};

void addPraktikan(struct Praktikan **praktikan, int *total_praktikan){
    // realokasi memori struktur dari total sebelumnya
    *praktikan = realloc(*praktikan, (*total_praktikan + 1) * sizeof(struct Praktikan));
    if (*praktikan == NULL){
        printf("Alokasi memori gagal.\n");
        exit(1);
    }

    struct Praktikan praktikan_baru;
    // Alokasi memori untuk nama praktikan, asumsi nama tidak pernah lebih dari 50 karakter
    praktikan_baru.nama = (char*)malloc(50 * sizeof(char));
    if(praktikan_baru.nama == NULL){
        printf("Alokasi memori gagal.\n");
        exit(1);
    }

    // Mendapatkan nama praktikan
    printf("\nMasukkan nama praktikan: ");
    getchar(); // Menghilangkan karakter newline dari input sebelumnya
    fgets(praktikan_baru.nama, 50, stdin);
    praktikan_baru.nama[strcspn(praktikan_baru.nama, "\n")] = '\0'; // menghapus karakter newline dari input nama

    // Mendapatkan NIM praktikan
    printf("Masukkan NIM praktikan: ");
    scanf("%d", &praktikan_baru.NIM);

    // Mendapatkan pemilihan soal praktikan
    printf("Masukkan pilihan soal praktikan: ");
    scanf("%d", &praktikan_baru.pemilihanSoal);

    // Mendapatkan hasil testcase praktikan
    printf("Masukkan pilihan hasil testcase praktikan secara berturut-turut (skala 0-10): ");
    scanf("%d %d %d %d %d", &praktikan_baru.test1, &praktikan_baru.test2, &praktikan_baru.test3, &praktikan_baru.test4, &praktikan_baru.test5);

    // Masukkan data ke dalam list
    (*praktikan)[*total_praktikan] = praktikan_baru;
    (*total_praktikan)++;
}

void calculateGrade(struct Praktikan *praktikan, int total_praktikan, int search_NIM){
    int found = 0;
    int total_value = 0;
    for (int i = 0; i < total_praktikan; i++){
        if (praktikan[i].NIM == search_NIM){
            printf("Praktikan ditemukan!\n");
            total_value += praktikan[i].test1 + praktikan[i].test2 + praktikan[i].test3 + praktikan[i].test4 + praktikan[i].test5;
            printf("Total nilai hasil testcase praktikan: %d/50.\n", total_value);
            found = 1;
            break;
        }
    }
    if (!found){
        printf("Praktikum dengan NIM %d ngga ada nih :(\n", search_NIM);
    }

}

int main(void){
    struct Praktikan *praktikan = NULL;
    int total_praktikan = 0;
    int opsi, search_NIM;

    do
    {
        printf("\nAutograder baru ni bos, kuy dipilih opsinya\n");
        printf("1. Tambah praktikan baru\n");
        printf("2. Hitung nilai praktikan\n");
        printf("3. Exit\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &opsi);

        switch (opsi){
            case 1:
                addPraktikan(&praktikan, &total_praktikan);
                break;
            case 2:
                printf("\nMasukkan NIM praktikan yang ingin dihitung nilainya: ");
                scanf("%d", &search_NIM);
                calculateGrade(praktikan, total_praktikan, search_NIM);
                break;
            case 3:
                printf("\nProgram selesai, yay.\n");
                break;
            default:
                printf("\nNgga ada opsi itu, bro.\n");
        }
    } while (opsi != 3);

    // Bebaskan memori pada array dinamis string dan struktur
    for(int i = 0; i < total_praktikan; i++){
        free(praktikan[i].nama);
    }
    free(praktikan);

    return 0;
}