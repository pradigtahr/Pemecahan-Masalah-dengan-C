#include <stdio.h>

void getDisplay(void){

    printf("List barang:\n");
    printf("1. Beras (Rp12.500)\n2. Daging (Rp21.700)\n3. Sayur (Rp3.900)\n4. Bumbu (Rp4.600)\n5. Sambal (Rp2.200)\n\n");
}

void getBarang(int jumlahBarang[5]) {
    printf("Jumlah barang secara berurutan: ");
    
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &jumlahBarang[i]);
    }

    // printf("%d %d %d %d %d\n", jumlahBarang[0], jumlahBarang[1], jumlahBarang[2], jumlahBarang[3], jumlahBarang[4]);
}

void totalBelanja(int hargaBarang[5], int jumlahBarang[5], int *total){
    *total = 0;
    for (int i = 0; i < 5; i++){
        *total += hargaBarang[i] * jumlahBarang[i];
    }
}



int main(void){

    // Deklarasi array untuk menyimpan harga dan jenis barang
    char jenisBarang[5][10] = {"Beras", "Daging", "Sayur", "Bumbu", "Sambal"};
    int hargaBarang[5] = {12500, 21700, 3900, 4600, 2200};
    int jumlahBarang[5] = {0, 0, 0, 0, 0};
    int uangPembeli, hargaBayar;

    // Tampilkan harga barang
    getDisplay();

    // Mendapatkan jumlah barang secara berurutan
    getBarang(jumlahBarang);

    // Mendapatkan uang yang dibawa oleh pembeli
    printf("Uang yang dibawa pembeli: ");
    scanf("%d", &uangPembeli);

    // Mendapatkan total belanjaan
    totalBelanja(hargaBarang, jumlahBarang, &hargaBayar);
    printf("Total belanjaan: %d", hargaBayar);

    // Menentukan kembalian




    return 0;
}