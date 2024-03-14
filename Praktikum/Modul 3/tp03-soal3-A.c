#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 255

int main(void){

    FILE *file1Pointer;
    char buffer[MAX_LEN];       // Variabel sementara untuk menyimpan pembacaan baris string

    // Membuka file bernama example.txt
    file1Pointer = fopen("tp03-soal3.txt", "r");

    // Cek apakah file ada dan berhasil dibuka
    if (file1Pointer == NULL){
        printf("file tidak ada.\n");
        return 1;
    }
    else{
        printf("File berhasil dibuka dengan mode 'r'.\n");
    }

    // Membaca tiap baris pada file menggunakan fungsi fgets
    while (fgets(buffer, sizeof(buffer), file1Pointer)){
        // Menampilkan tiap baris yang dibaca pada file
        printf("Baris yang dibaca pada baris: %s", buffer);
    }

    fclose(file1Pointer);

    return 0;
}