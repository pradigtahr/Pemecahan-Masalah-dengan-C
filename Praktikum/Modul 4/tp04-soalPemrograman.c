/*EL2208 Praktikum Pemecahan Masalah dengan C 2023/2024
*TP Modul         : 4 - Recursion
*Hari dan Tanggal : Selasa, 19 Maret 2024 
*Nama (NIM)       : Pradigta Hisyam Ramadhan (18322008)
*Nama File        : tp04-soalPemrograman.c
*Deskripsi        : Program digunakan untuk mencari jumlah pengulangan sebuah bilangan, apabila
                    kuadrat-kuadrat digitnya dikuadratkan sampai mendapatkan hasil 1. 
*/

#include <stdio.h>
#define MAX_SIZE 1000


// Fungsi rekursif untuk menghitung sequence angka
int countIteration(int n, int visited[MAX_SIZE]) {
    // Deklarasi variabel lokal
    int sum, temp, digit;

    // Kasus basis
    if (n == 1){
        return 0;
    }
    else if (visited[n] == 1){
        // Angka diulang dua kali, menuju infinite loop, diindikasi dengan nilai -1 (error)
        return -1;
    }
    else{
        // Beri penanda pada array untuk angka yang sudah dilewati
        visited[n] = 1;

        // Menjumlahkan kuadrat digit-digit angka yang diinput
        sum = 0;
        temp = n;
        while(temp != 0){
            digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }

        // Rekursif
        int nextN = countIteration(sum, visited);
        if (nextN == -1){
            return -1; // exit infinite loop
        }
        return 1 + nextN;
    }
}

void checkFiniteLoop(int iteration){
    if (iteration == -1){
        printf("Infinite.");
    }
    else{
        printf("%d", iteration);
    }
}

int main() {
    int number, pengulangan;
    int visited[MAX_SIZE]; // Array untuk menyimpan angka yang sudah dikunjungi

    // Mendapatkan bilangan
    printf("Masukkan bilangan N: ");
    scanf("%d", &number);
    
    // Memanggil fungsi rekursif untuk menghitung sequence angka dan mencetak hasilnya
    pengulangan = countIteration(number, visited);

    // Cek apakah pengulangan tak berhingga atau tidak
    checkFiniteLoop(pengulangan);

    return 0;
}
