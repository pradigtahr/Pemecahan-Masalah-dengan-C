#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 1000

// Fungsi rekursif untuk menghitung sequence angka
int hitungSequence(int n, bool visited[MAX_SIZE]) {
    // Kasus basis
    if (n == 1) {
        return 0;
    } else if (n >= MAX_SIZE || visited[n]) {
        // Angka diulang dua kali, menuju infinite loop, diindikasi dengan nilai -1 (error)
        return -1;
    } else {
        // Tandai angka yang sedang diproses
        visited[n] = true;

        int sum = 0;
        int temp = n;
        while (temp != 0) {
            int digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }
        
        // Rekursif
        int next = hitungSequence(sum, visited);
        if (next == -1) { // If there is a loop encountered in subsequent calls, return -1
            return -1;
        }
        return 1 + next; // Return 1 plus the number of iterations from subsequent calls
    }
}

int main() {
    int number, pengulangan;
    bool visited[MAX_SIZE] = {false}; // Array untuk menyimpan apakah angka sudah dikunjungi

    // Mendapatkan bilangan
    printf("Masukkan bilangan N: ");
    scanf("%d", &number);

    // Memanggil fungsi rekursif untuk menghitung sequence angka dan mencetak hasilnya
    pengulangan = hitungSequence(number, visited);

    // Check for loop
    if (pengulangan == -1) {
        printf("Error: Sequence enters into an infinite loop.\n");
    } else {
        printf("Jumlah pengulangan: %d\n", pengulangan);
    }

    return 0;
}
