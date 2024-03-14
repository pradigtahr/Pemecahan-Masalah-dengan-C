/*EL2208 Praktikum Pemecahan Masalah dengan C 2023/2024
*Modul            : 2
*Hari dan Tanggal : Jumat, 8 Maret 2024 
*Nama (NIM)       : Pradigta Hisyam Ramadhan (18322008)
*Asisten (NIM)    : Israini Azhar Ramadhan (18321016)
*Nama File        : main.c
*Deskripsi        : Program digunakan untuk menampilkan waktu istirahat dalam 
                    format jam dan menit
*/

#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk memeriksa apakah waktu masuk atau keluar valid
int isValidTime(int jMasuk, int mMasuk, int jKeluar, int mKeluar, char tanda) {
    if(jMasuk < 24 && jKeluar < 24 && mMasuk <= 60 && mKeluar <= 60 && tanda == ':'){ // Masukkan valid
        return 1;
    }
    else{
        return 0;
    }
}

// Fungsi untuk menghitung dan mencetak durasi waktu istirahat -- UPDATE
void hitungDurasiIstirahat(int jMasuk, int mMasuk, int jKeluar, int mKeluar, int *jam, int *menit) {
    int totalMenitMasuk = jMasuk * 60 + mMasuk;
    int totalMenitKeluar = jKeluar * 60 + mKeluar;

    int diffMenit = (totalMenitKeluar - totalMenitMasuk + 24 * 60) % (24 * 60);

    *jam = diffMenit / 60;
    *menit = diffMenit % 60;
}


int main() {
    int jam_masuk, jam_keluar, menit_masuk, menit_keluar;
    int total_jam, total_menit;
    char sign;

    // Input waktu masuk dan keluar
    printf("Masukkan waktu masuk (format HH:MM): ");
    scanf("%d%c%d", &jam_masuk, &sign, &menit_masuk);
    printf("Masukkan waktu keluar (format HH:MM): ");
    scanf("%d%c%d", &jam_keluar, &sign, &menit_keluar);

    // printf("%d %d %d %d", jam_masuk, menit_masuk, jam_keluar, menit_keluar);

    // Validasi input
    if(isValidTime(jam_masuk, menit_masuk, jam_keluar, menit_keluar, sign)){
        // Memanggil fungsi untuk menghitung durasi waktu istirahat
        hitungDurasiIstirahat(jam_masuk, menit_masuk, jam_keluar, menit_keluar, &total_jam, &total_menit);
        if (total_jam != 0 && total_menit != 0){
            printf("Durasi waktu istirahat: %d jam %d menit", total_jam, total_menit);
        }
        else if(total_jam != 0 && total_menit == 0){
            printf("Durasi waktu istirahat: %d jam", total_jam);
        }
        else if(total_jam == 0 && total_menit != 0){
            printf("Durasi waktu istirahat: %d menit", total_menit);
        }
        else{
            printf("Durasi waktu istirahat: %d jam", 24);
        }
    }

    else{
        printf("Format waktu salah!");
    }
        
    return 0;
}
