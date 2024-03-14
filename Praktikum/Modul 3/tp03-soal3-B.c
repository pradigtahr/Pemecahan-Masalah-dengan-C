#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 255

int main(void){

    FILE *file1Pointer;
    // Deklarasi string yang akan ditulis ke dalam file
    char content[] = "Pradigta Hisyam Ramadhan\n18322008\nTeknik Biomedis\nTugas Pendahuluan Modul 3: Strings and External Files";

    // Membuka file bernama example.txt
    file1Pointer = fopen("tp03-soal3.txt", "w");

    // Cek apakah file ada dan berhasil dibuka
    if (file1Pointer == NULL){
        printf("file tidak ada.\n");
        return 1;
    }
    else{
        printf("File berhasil dibuka dengan mode 'w'.\n");
    }

    // Menuliskan konten string ke dalam file menggunakan fungsi fputs
    if (fputs(content, file1Pointer) == EOF){
        printf("Terjadi error saat menuliskan konten ke file.\n");
        fclose(file1Pointer);
        return 1;
    }

    printf("Konten berhasil ditulis ke dalam file.\n");

    fclose(file1Pointer);

    return 0;
}