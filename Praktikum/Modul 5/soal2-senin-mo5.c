#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 100

struct Kader {
    char *nama;
    char *partai;
    int suara;
};

void getKader(int *n){
    printf("Masukkan jumlah kader partai: ");
    scanf("%d", n);
}

void getData(struct Kader *kader, int n){
    for (int i = 0; i < n; i++){
        // Alokasikan memori untuk nama dan partai
        kader[i].nama = (char *)malloc(MAX_STRING * sizeof(char));
        kader[i].partai = (char *)malloc(MAX_STRING * sizeof(char));

        // Mendapatkan informasi, lalu assign ke struktur
        printf("Informasi kader ke-%d : ", i+1);
        scanf("%s %s %d", (kader+i)->nama, (kader+i)->partai, &(kader+i)->suara);
    }
}

void getAnggotaDPR(struct Kader *kader, int n){
    int max = kader[0].suara, flag = 0;
    for (int i = 1; i < n; i++){
        if (kader[i].suara > max){
            max = kader[i].suara;
            flag = i;
        }
    }

    printf("\nAnggota Dewan Perwakilan Rakyat Anti Korupsi (DPRAK) tahun 2024\n");
    printf("%s %s %d\n", kader[flag].nama, kader[flag].partai, kader[flag].suara);
    printf("Semoga amanah Anti Korupsi #WakandaForever");
}


int main(void){
    struct Kader *kader;
    int n;

    // Mendapatkan jumlah kader partai dan alokasi memori sesuai jumlah kader
    getKader(&n);
    kader = (struct Kader *)malloc(n * sizeof(struct Kader));

    // Mendapatkan data kader
    getData(kader, n);

    // Mendapatkan pemenang pemilu
    getAnggotaDPR(kader, n);
    
    return 0;
}