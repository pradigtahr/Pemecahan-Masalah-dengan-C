/*EL2208 Praktikum Pemecahan Masalah dengan C
Modul           : 1 - Overview of C Language
Percobaan       : Tutorial 02
Hari/Tanggal    : Kamis, 29 Februari 2024
Pembuat         : Irfan Tito Kurniawan, ditulis ulang oleh Pradigta Hisyam Ramadhan
Nama File       : tutorial-m01-02.c
Deskripsi       : Source code tutorial untuk modul 1*/

#include <stdio.h>
#define MAX_ENTRY 20

int main(void)
{
    // Deklarasi array of int
    int arr[MAX_ENTRY];
    int entry_amt;

    // Input jumlah masukan
    printf("Input jumlah masukan (maksimum 20): ");
    scanf("%d", &entry_amt);

    // Struktur kontrol kondisional dengan validasi input
    if (entry_amt < 0 || entry_amt > MAX_ENTRY){
        printf("Error, jumlah masukan salah.\n");
    }
    else{
        // Struktur kontrol iteratif untuk i/o nilai array
        // Input elemen array
        printf("\nMasukkan %d bilangan bulat:\n", entry_amt);
        for (int i = 0; i < entry_amt; i++){
            scanf("%d", &arr[i]);
        }
        // Tampilkan isi elemen array
        printf("\nIsi Array: [");
        for (int i = 0; i < entry_amt; i++){
            if (i == entry_amt - 1){
                printf("%d].", arr[i]);
            }
            else{
                printf("%d, ", arr[i]);
            }
        }
    }

    // Input bilangan yang ingin dicari dalam array
    int key;

    printf("\n\nInput bilangan yang ingin dicari dalam array: ");
    scanf("%d", &key);

    // Cari bilangan dalam array
    int idx = 0;
    int found = 0;

    // Cari bilangan selama indeks masih di dalam batas array dan bilangan belum ditemukan
    while (idx < entry_amt && !found){
        // Elemen ditemukan
        if (arr[idx] == key){
            found = 1;
        }
        else{
            idx++;
        }
    }

    // Cetak hasil pencarian
    if (found){
        printf("Bilangan %d ditemukan pada indeks ke-%d. \n", key, idx);
    }
    else {
        printf("Bilangan %d tidak ada pada array.", key);
    }

    return 0;
}