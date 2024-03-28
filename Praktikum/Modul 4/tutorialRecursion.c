#include <stdio.h>
#include <math.h>
#include <string.h>

// Function prototypes
int recursive_power(int num, int pow);

void recursive_print(int *arr, int size, int cur_idx);

int check_palindrom(char *s);

int check_palindrom_helper(char *s, int idx_front, int idx_rear);


int main(void){
    // Bagian 1 - Hitung pangkat bilangan bulat
    int num;
    int pow;
    printf("\n1. Hitung Pangkat\n");
    printf("Masukkan angka basis: ");
    scanf("%d", &num);
    printf("Masukkan orde angka: ");
    scanf("%d", &pow);
    printf("Hasil dari %d pangkat %d adalah: %d\n", num, pow, recursive_power(num, pow));

    // Bagian 2 - Print array secara rekursif
    int arr[] = {0, 1, 2, 3, 4, 5};
    printf("\n2. Print Rekursif\n");
    recursive_print(arr, sizeof(arr)/sizeof(arr[0]), 0);

    // Bagian 3 - Periksa palindrom
    char *s;
    printf("\n3. Cek palindrom\n");
    printf("Masukkan karakter: ");
    scanf("%s", s);
    if(check_palindrom(s)){
        printf("'%s' adalah palindrom.\n", s);
    }
    else{
        printf("'%s' bukan palindrom.\n", s);
    }

    return 0;
}

// Function realization
int recursive_power(int num, int pow){
    //Kasus basis
    if (pow == 0)
        return 1;
    else
        //rekuren
        return num * recursive_power(num, pow-1);
}

void recursive_print(int *arr, int size, int cur_idx){
    // rekuren
    if (cur_idx < size){
        printf("%d ", arr[cur_idx]);
        recursive_print(arr, size, cur_idx+1);
    }
    //basis, ketika cur_idx == size
    else{
        printf("\n");
    }
}

int check_palindrom(char *s){
    // fungsi ini hanya digunakan untuk memanggil fungsi check_palindrom tanpa indeks-indeks
    // Memanggil fungsi check_palindrom_helper dengan idx_front = 0 dan idx_rear elemen string paling belakang
    return check_palindrom_helper(s, 0, strlen(s)-1);
}

int check_palindrom_helper(char *s, int idx_front, int idx_rear){
    // Kasus basis apabila panjang ganjil
    if (idx_front == idx_rear)
        return 1;
    
    // Kasus basis apabila panjang genap
    if (idx_front == idx_rear - 1 && s[idx_front] == s[idx_rear])
        return 1;
    
    // Rekuren, ketika belum sampai tengah
    if (s[idx_front] != s[idx_rear])
        return 0;
    else
        // Apabila masih sama, cek pasangan karakter selanjutnya
        return check_palindrom_helper(s, idx_front + 1, idx_rear - 1);
}