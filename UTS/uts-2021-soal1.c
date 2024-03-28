#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Fungsi untuk mendapatkan rasio
int* getRatio(int penduduk[5], int faskes[5]){
    int *ratio = (int *)malloc(5*sizeof(int));
    for (int i=0; i<5; i++){
        ratio[i] = penduduk[i] / faskes[i];
    }

    return ratio;
}

// Fungsi untuk menentukan kecamatan yang perlu menambah faskes
void checkFaskes(char *penduduk[5], int ratio[5]){
    for (int i=0; i<5; i++){
        if (ratio[i] < 1000){
            printf("Kecamatan %s perlu faskes tambahan.\n", penduduk[i]);
        }
    }
}

int main(void){

    char *kecamatan[5] = {"A", "B", "C", "D", "E"};
    int jumlah_penduduk[5] = {5000, 12000, 8000, 4000, 10000};
    int jumlah_faskes[5] = {6, 12, 10, 4, 8};
    int *ratio_kecamatan;

    // Mendapatkan rasio masing-masing kecamatan
    ratio_kecamatan = getRatio(jumlah_penduduk, jumlah_faskes);

    // Cek apakah faskes perlu ditambah
    checkFaskes(kecamatan, ratio_kecamatan);


    return 0;
}