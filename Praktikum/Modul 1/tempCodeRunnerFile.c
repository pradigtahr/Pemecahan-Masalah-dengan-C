/*EL2208 Praktikum Pemecahan Masalah dengan C 2023/2024
*Modul            : 1
*Hari dan Tanggal : Jumat, 1 Maret 2024 
*Nama (NIM)       : Pradigta Hisyam Ramadhan (18322008)
*Asisten (NIM)    : Israini Azhar Ramadhan (18321016)
*Nama File        : main.c
*Deskripsi        : Program digunakan untuk menampilkan deret bilangan bulat, 
                    prima, dan fibonacci sesuai dengan input pengguna
*/

#include <stdio.h>

void displayMenu(void) {
    printf("PROGRAM BILANGAN\n");
    printf("1. Bilangan Bulat\n2. Bilangan Prima\n3. Bilangan Fibonacci\n4. Exit");
}

int main(void) {
    // Deklarasi variabel

    int numKey, upRange, lowRange;
    // Display menu untuk memilih jenis bilangan yang ingin ditampilkan
    displayMenu();

    do {

        // Input user: jenis bilangan dan rentang bilangan tersebut
        do {
            printf("\n\nMasukkan jenis bilangan yang diinginkan: ");
            scanf("%d", &numKey);

            // Validasi input
            if (numKey < 1 || numKey > 4) {
                printf("\nInput pada program salah!");
            } else {
                if (numKey != 4) {
                    printf("\nMasukkan bilangan awal: ");
                    scanf("%d", &lowRange);
                    printf("Masukkan bilangan akhir: ");
                    scanf("%d", &upRange);
                    if (lowRange >= upRange) {
                        printf("\nInput pada program salah!");
                    }
                }
            }
        } while (numKey < 1 || numKey > 4 || (numKey != 4 && lowRange >= upRange));

        // If user chooses Exit (numKey = 4), break out of the loop
        if (numKey == 4) {
            break;
        }

        // Menentukan jenis deret bilangan berdasarkan input yang diberikan
        // Deret bilangan bulat
        if (numKey == 1) {
            printf("\nDeret Bilangan Bulat\n\n");
            for (int i = lowRange; i <= upRange; i++) {
                printf("%d ", i);
            }

        // Deret bilangan prima
        } else if (numKey == 2) {
            printf("\nDeret Bilangan Prima\n\n");
            for (int i = lowRange; i <= upRange; i++) {
                if (i > 1) {
                    // cek bilangan prima
                    int isPrime = 1; // Asumsi i adalah bilangan prima
                    for (int j = 2; j <= i / 2; j++) {
                        if (i % j == 0) {
                            // i bukan prima
                            isPrime = 0;
                        }
                    }
                    // Cetak hasil prima
                    if (isPrime) {
                        printf("%d ", i);
                    }
                }
            }

        // Deret bilangan fibonacci
        } else if (numKey == 3) {
            printf("\nDeret Bilangan Fibonacci\n\n");
            int n1 = 0, n2 = 1, n3 = 0;

            // Loop untuk membandingkan apakah i merupakan bilangan fibonacci atau tidak
            while (n3 <= upRange) {
                if (n3 >= lowRange) {
                    printf("%d ", n3);
                }
                n3 = n1 + n2;
                n1 = n2;
                n2 = n3;
            }
        }
    } while (numKey != 4);

    printf("\nProgram selesai");

    return 0;
}
