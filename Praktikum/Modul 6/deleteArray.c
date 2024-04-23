#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAHASISWA 100 // Jumlah maksimum Mahasiswa

typedef struct Mahasiswa {
    char nama[50];
    int nim;
    float ipk;
} Mahasiswa;

void hapusMahasiswa(Mahasiswa array[], int *size, int nim) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (array[i].nim == nim) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                array[j] = array[j + 1];
            }
            (*size)--;
            printf("Mahasiswa dengan NIM %d berhasil dihapus!\n", nim);
            break;
        }
    }
    if (!found) {
        printf("Mahasiswa dengan NIM %d tidak ada!\n", nim);
    }
}

int main(void) {
    Mahasiswa array[MAX_MAHASISWA];
    int size = 0; // Inisiasi awal jumlah mahasiswa

    // Sampel data mahasiswa dalam bentuk array
    strcpy(array[size].nama, "John");
    array[size].nim = 12345;
    array[size].ipk = 3.75;
    size++;

    strcpy(array[size].nama, "Alice");
    array[size].nim = 54321;
    array[size].ipk = 3.95;
    size++;

    // Meminta masukan dari pengguna untuk menghapus mahasiswa yang akan dihapus berdasarkan NIM
    int nimToDelete;
    printf("Masukkan NIM mahasiswa yang ingin dihapus: ");
    scanf("%d", &nimToDelete);

    // Memanggil fungsi untuk menghapus mahasiswa
    hapusMahasiswa(array, &size, nimToDelete);

    // Menampilkan array yang tersisa
    printf("Data Mahasiswa setelah penghapusan:\n");
    for (int i = 0; i < size; i++) {
        printf("Nama: %s, NIM: %d, IPK: %.2f\n", array[i].nama, array[i].nim, array[i].ipk);
    }

    return 0;
}
