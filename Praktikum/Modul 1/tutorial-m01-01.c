/*EL2208 Praktikum Pemecahan Masalah dengan C
Modul           : 1 - Overview of C Language
Percobaan       : Tutorial 01
Hari/Tanggal    : Kamis, 29 Februari 2024
Pembuat         : Irfan Tito Kurniawan, ditulis ulang oleh Pradigta Hisyam Ramadhan
Nama File       : tutorial-m01-01.c
Deskripsi       : Source code tutorial untuk modul 1*/

#include <stdio.h>
#include <math.h>
// Macro definition
#define EULER 2.7128

int main(void)
{
    // blok1: input nilai variabel
    int i;
    float f;
    char c;

    // Input nilai variabel
    printf("Masukkan nilai bilangan bulat i: ");
    scanf("%d", &i);

    printf("Masukkan nilai karakter c: ");
    scanf(" %c", &c);

    printf("Masukkan nilai bilangan real f: ");
    scanf("%f", &f);

    //Menampilkan nilai variabel yang sudah di-input
    printf("Nilai i:\t%d\n", i);
    printf("Nilai c:\t%c\n", c);
    printf("Nilai f:\t%.3f\n\n", f);

    //blok2: assignment dan ekspresi
    // Contoh perkalian
    i = i*2;
    printf("Nilai i setelah dikali dengan 2: %d\n", i);

    // Contoh assignment
    i = 5;
    printf("Nilai i setelah assignment: %d\n", i);

    // Contoh boolean, diwakilkan dengan 0/not 0
    printf("Apakah nilai i kurang dari 5? %d\n", i < 5);
    printf("Apakah nilai i sama dengan 5? %d\n\n", i == 5);

    // blok 3: perhitungan
    printf("Nilai bilangan euler: %3f\n", EULER);
    printf("Dengan math.h - hasil operasi dari e^(%d): %.3f\n", i, exp(i));
    printf("Dengan macro - hasil operasi dari e^(%d): %.3f\n", i, pow(EULER, i));

    return 0;
}