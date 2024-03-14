#include <stdio.h>
#include <string.h>

#define MAX_CAKES 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hargaPokok;
    int hargaJual;
    int jumlahTerjual;
} Cake;

void bukaToko(Cake cakes[]) {
    printf("BUKA TOKO\n");
    for (int i = 0; i < MAX_CAKES; i++) {
        printf("Masukkan jenis ke-%d> ", i + 1);
        scanf("%s %d %d", cakes[i].name, &cakes[i].hargaPokok, &cakes[i].hargaJual);
        cakes[i].jumlahTerjual = 0;
    }
}

void jualKue(Cake cakes[]) {
    char entryKue[MAX_NAME_LENGTH];
    int entryJumlah = 1;

    while (1) {
        printf("Entry> ");
        scanf("%s %d", entryKue, &entryJumlah);

        if (strcmp(entryKue, "TUTUP") == 0 && entryJumlah == 0) {
            break;
        }

        int kueTersedia = 0;

        for (int j = 0; j < MAX_CAKES; j++) {
            if (strcmp(entryKue, cakes[j].name) == 0) {
                printf("== %s %d buah terjual\n", entryKue, entryJumlah);
                cakes[j].jumlahTerjual += entryJumlah;
                kueTersedia = 1;
                break;
            }
        }

        if (!kueTersedia) {
            printf("== %s tidak tersedia\n", entryKue);
        }
    }
}

void tutupToko(Cake cakes[]) {
    printf("\n== TUTUP TOKO\n");
    for (int i = 0; i < MAX_CAKES; i++) {
        printf("== %s %d buah terjual, keuntungan %d\n", cakes[i].name, cakes[i].jumlahTerjual, 
               (cakes[i].hargaJual * cakes[i].jumlahTerjual) - (cakes[i].hargaPokok * cakes[i].jumlahTerjual));
    }
}

int main(void) {
    Cake cakes[MAX_CAKES];

    bukaToko(cakes);
    jualKue(cakes);
    tutupToko(cakes);

    return 0;
}
