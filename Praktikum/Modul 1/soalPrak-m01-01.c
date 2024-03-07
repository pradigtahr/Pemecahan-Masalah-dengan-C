#include <stdio.h>
#define MAX_ENTRY 100

int validateInput(int n){
    if (n <= 0 || n > 100){
        return 0;
    }
    else {
        return 1;
    }
}

int main(void){
    int n, arr[MAX_ENTRY];

    // Menerima jumlah mahasiswa
    printf("Masukkan Jumlah Murid\t: ");
    scanf("%d", &n);

    // Validasi input
    if (validateInput(n)){
        for (int i = 0; i < n; i++){
            printf("Masukkan Nilai ke-%d\t: ", i+1);
            scanf("%d", &arr[i]);
        }
    }
    else{
        printf("Jumlah tidak valid");
    }

    // Mencari ranking
    int key;
    printf("\nMasukkan peringkat yang ingin dilihat\t: ");
    scanf("%d", &key);

    // Menampilkan hasil
    if (key < n){
        printf("Peringkat ke-%d memiliki nilai : %d", key, arr[key-1]);
    }
    else{
        printf("Peringkat di luar range");
    }

    return 0;
}