/*EL2208 Praktikum Pemecahan Masalah dengan C 2023/2024
*TP Modul         : 2
*Hari dan Tanggal : Selasa, 5 Maret 2024 
*Nama (NIM)       : Pradigta Hisyam Ramadhan (18322008)
*Nama File        : TP-m02.c
*Deskripsi        : Program digunakan untuk menampilkan hasil perkalian array of integers yang
                    dimasukkan oleh pengguna
*/

#include <stdio.h>

int multiply(int arr[5], int *result){
    // Deklarasi nilai awal result
    *result = arr[0];
    for(int i = 0; i < 5; i++){
        *result = *result * arr[i];
    }
    return *result;
}

int main(){
    int Array[5];
    int result;
    //input elemen array
    printf("#Input\n");
    for (int i = 0; i < 5; i++){
        scanf("%d", &Array[i]);
    }

    //Output perkalian elemen array
    printf("\n#Output\n");
    result = multiply(Array, &result);
    printf("%d", result);

    return 0;
}