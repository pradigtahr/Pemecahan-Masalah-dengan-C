#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

int main(void){
    const char dummy[7] = "Henlo!";
    // Input nama file
    char filename[MAX_LEN];             // Deklarasi variabel untuk menyimpan file
    printf("\nMasukkan nama file: ");
    scanf("%s", &filename);

    // Buka file untuk dibaca, disimpan di variabel dengan nama 'stream'
    FILE* stream = fopen(filename, "r");

    // Array nama mahasiswa
    char names[MAX_LEN][MAX_LEN];
    // Array nilai mahasiswa
    float score[MAX_LEN];

    // Variabel penyimpan baris dari file sementara
    char line[MAX_LEN];

    // Token penyimpan string sementara untuk parsing
    char* token;

    // Iterator penanda indeks array, pada akhir iterasi nilai i akan sama dengan jumlah baris pada file
    int i = 0;

    // Baca file baris demi baris hingga habis
    while(fgets(line, MAX_LEN, stream)){
        // Parse baris
        // Ambil string pada baris hingga tanda koma (koma tidak ikut dibaca)
        token = strtok(line, ",");

        // Salin string dari token ke array nama
        strcpy(names[i], token);

        // Iterasi
        ++i;
    }

    // Cari nilai maksimum, minimum, dan rata-rata nilai 
    float max = score[0]; 
    float min = score[0]; 
    float sum = score[0];

    // Index nilai maksimum dan minimum pada array 
    int max_idx = 0; 
    int min_idx = 0;

    for (int j = 1; j < i; ++j) { 
    // Cari nilai maksimum dan minimum 
        if (score[j] > max) { 
            max = score[j]; max_idx = j; 
        } 
        if (score[j] < min) { 
            min = score[j]; min_idx = j;
        }

    // Jumlahkan nilai untuk menghitung rata-rata 
        sum += score[j];
    }

    // Hitung nilai rata-rata
    float mean = sum / i;

    // Print semua nama dan nilai
    for (int j = 0; j < i; ++j){
        printf("%s memperoleh nilai %.2f\n", names[j], score[j]);
    }

    // Print statistik
    printf("\nStatistik:\n"); 
    printf("Nilai tertinggi: %.2f, atas nama %s\n", max, names[max_idx]); 
    printf("Nilai terendah: %.2f, atas nama %s\n", min, names[min_idx]); 
    printf("Nilai rata-rata: %.2f\n", mean);

    // Nama sebagai kunci pencarian
    char key[MAX_LEN];
    
    // Input kunci pencarian
    printf("\nCari nilai atas nama: ");
    scanf("%s", &key);

    // Hitung panjang nama dengan strlen dan tampilkan sebagai long int
    printf("%s terdiri atas %ld karakter\n", key, strlen(key));

    // Cari nama hingga ditemukan atau hingga array habis
    int found = 0;
    int j = 0;

    while (j < i && !found){
        // Perbandingan string akan bernilai 0 jika kedua string sama persis
        if (!strcmp(key, names[j])){
            found = 1;
        }
        else{
            ++j;
        }
    }

    // Print nilai kunci pencarian bila ditemukan
    if (found){
        printf("%s memperoleh nilai: %.2f\n", key, score[j]);
    }
    else{
        printf("%s tidak ada.\n", key);
    }

    // Tutup file
    fclose(stream);


    return 0;
}