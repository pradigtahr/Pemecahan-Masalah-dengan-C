/*EL2208 Praktikum Pemecahan Masalah dengan C 2023/2024
*TP Modul         : 3
*Hari dan Tanggal : Senin, 11 Maret 2024 
*Nama (NIM)       : Pradigta Hisyam Ramadhan (18322008)
*Nama File        : tp-03-soalPemrograman.c
*Deskripsi        : Program digunakan untuk menampilkan nama dari sebuah file web.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 255

int main(void) {
    // Deklarasi variabel
    FILE *filePointer;
    char buffer[MAX_LINE];

    // membuka file web.txt
    filePointer = fopen("web.txt", "r");

    // Cek apakah file ada dan dapat dibuka
    if (filePointer == NULL) {
        printf("Folder tidak ada atau tidak dapat dibuka!\n");
        return 1;
    }

    // File ada dan berhasil dibuka
    printf("Folder berhasil dibuka!\n\n");

    // Menampilkan string pada tiap baris file dengan urutan indeks yang terbalik
    printf("Web praktikum:\n");

    // Deklarasi variabel untuk menyimpan array of strings dan panjang baris. 
    char lines[MAX_LINE][100];
    int lineCount = 0;  // Pada akhir iterasi, nilai lineCount akan sama dengan panjang baris

    // Membaca semua baris dan simpan nilainya ke dalam array
    while (fgets(buffer, sizeof(buffer), filePointer) != NULL && lineCount < MAX_LINE) {
        // Hapus karakter newline pada file
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        // Salin string pada baris ke dalam array lines
        strcpy(lines[lineCount], buffer);
        lineCount++;
    }

    // Hasil pembacaan file dengan indeks terbalik
    for (int i = lineCount - 1; i >= 0; i--) {
        // Tampilkan string pada file dengan titik, kecuali pada indeks terakhir yang diproses
        printf("%s%s", lines[i], (i == 0) ? "" : ".");
    }

    // Tutup file setelah selesai
    fclose(filePointer);

    return 0;
}
