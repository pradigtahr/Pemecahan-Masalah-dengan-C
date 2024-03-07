/*
*Nama (NIM)       : Pradigta Hisyam Ramadhan (18322008)
*Nama File        : 18322008-pradigtahr.c
*Deskripsi        : Tugas liburan; membuat program untuk menghitung keuntungan penjualan sebuah toko kue
                    berdasarkan kue yang tersedia.
*/

#include <stdio.h>
#include <string.h>

void bukaToko(char namaKue[5][20], int hargaPokok[5], int hargaJual[5]){
    printf("BUKA TOKO\n");
    for (int i = 0; i < 5; i++){
        printf("Masukkan jenis ke-%d> ", i+1);
        scanf("%s%d%d", &namaKue[i], &hargaPokok[i], &hargaJual[i]);
    }
    strcpy(namaKue[5], "");
}

void jualKue(char namaKue[5][20], int jumlahKue[5]) {
    char entryKue[20] = "";
    int entryJumlah = 1, i = 0;

    while (strcmp(entryKue, "TUTUP") != 0 && entryJumlah != 0) {
        printf("Entry> ");
        scanf("%s%d", entryKue, &entryJumlah);

        if (strcmp(entryKue, "TUTUP") == 0 && entryJumlah == 0){
            break;
        }

        // Deklarasi flag untuk mengetahui apakah kue yang di entry tersedia atau tidak
        int kueTersedia = 0;

        // Pengulangan untuk mengecek apakah entryKue ada dalam list namaKue
        for (int j = 0; j < 5; j++) {
            if (strcmp(entryKue, namaKue[j]) == 0) {
                printf("== %s %d buah terjual\n", entryKue, entryJumlah);
                jumlahKue[j] += entryJumlah;
                kueTersedia = 1;    // Kue ditemukan pada list
                break;              // Break loop jika kue nama kue ditemukan pada list kue
            }
        }

        if (!kueTersedia) {
            printf("== %s tidak tersedia\n", entryKue);
        }

        i++;
    }
}

void tutupToko(char namaKue[5][20], int hargaPokok[5], int hargaJual[5], int jumlahKue[5]){
    printf("\n== TUTUP TOKO\n");
    // Menghitung keuntungan berdasarkan jumlah kue yang terjual
    for (int i = 0; i < 5; i++){
        printf("== %s %d buah terjual, keuntungan %d\n", namaKue[i], jumlahKue[i], hargaJual[i]*jumlahKue[i] - hargaPokok[i]*jumlahKue[i]);
    }
}



int main(void){
    // Deklarasi variabel
    char    namaKue_main[5][20];
    int     hargaPokok_main[5],
            hargaJual_main[5],
            jumlahKue_main[5] = {0, 0, 0, 0, 0};

    // Buka toko, dapatkan 5 jenis kur, harga pokok, dan harga jualnya
    bukaToko(namaKue_main, hargaPokok_main, hargaJual_main);

    // Menerima input penjualan kue
    jualKue(namaKue_main, jumlahKue_main);

    // Tutup toko setelah selesai melakukan semua penjualan
    tutupToko(namaKue_main, hargaPokok_main, hargaJual_main, jumlahKue_main);

    return 0;
}