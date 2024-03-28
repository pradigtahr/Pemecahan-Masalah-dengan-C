#include <stdio.h>

// Fungsi untuk menghitung sequence angka
int hitungSequence(int n) {
    // Tortoise and hare pointers
    int tortoise = n;
    int hare = n;
    
    // Move hare twice as fast as tortoise
    do {
        tortoise = getNextNumber(tortoise);
        hare = getNextNumber(getNextNumber(hare));
        
        // If hare reaches 1 or a cycle is detected, return
        if (tortoise == 1 || hare == 1 || tortoise == hare)
            break;
    } while (1);
    
    // If tortoise reaches 1, it's a happy number
    if (tortoise == 1)
        return 0;
    else // Otherwise, it's a cycle
        return -1;
}

// Fungsi untuk menghitung nilai berikutnya dalam sequence
int getNextNumber(int n) {
    int sum = 0;
    while (n) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

int main() {
    int number, pengulangan;

    // Mendapatkan bilangan
    printf("Masukkan bilangan N: ");
    scanf("%d", &number);

    // Memanggil fungsi rekursif untuk menghitung sequence angka dan mencetak hasilnya
    pengulangan = hitungSequence(number);

    // Check for loop
    if (pengulangan == -1) {
        printf("Error: Sequence enters into an infinite loop.\n");
    } else {
        printf("Jumlah pengulangan: %d\n", pengulangan);
    }

    return 0;
}
