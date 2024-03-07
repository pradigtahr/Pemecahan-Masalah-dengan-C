#include <stdio.h>
#include <stdbool.h>  // Header untuk mengakses tipe data boolean
#define LOWER_RANGE 0
#define UPPER_RANGE 100

// Fungsi swap untuk menukar dua elemen pada array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk melakukan bubble sort
void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            // Jika elemen saat ini lebih besar dari elemen berikutnya, tukar posisi
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

    // int i = 1;
    // while (i < n ){
    //     int j = 0;
    //     while (j < n - 1){
    //         // Jika elemen saat ini lebih besar dari elemen berikutnya, tukar posisi
    //         if (arr[j] > arr[j + 1]){
    //             swap(&arr[j], &arr[j + 1]);
    //         }
    //         j++;
    //     }
    //     i++;
    // }
}

// Fungsi untuk menampilkan elemen-elemen array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    // Deklarasi variabel
    int n;
    bool validInput = true;  // Flag untuk mengetahui validitas input
    
    // Menerima input bilangan N
    printf("N = ");
    scanf("%d", &n);

    // deklarasi matriks berukuran N untuk menampung nilai yang diberikan
    int arr[n];

    // Menerima N buah bilangan dari rentang yang sudah ditentukan
    for (int i = 0; i < n; i++)
    {
        // Ambil nilai dari user
        int temp = 0;    // Variabel penampung sementara nilai input user
        printf("Nilai ke-%d:\t", i+1);
        scanf("%d", &temp);
        if (temp >= LOWER_RANGE && temp <= UPPER_RANGE)
        {
            // Nilai temp dimasukkan ke array
            arr[i] = temp;
        }
        else
        {
            printf("Invalid input!");
            validInput = false;
            break;
        }
    }

    // Cek validitas nilai yang dimasukkan pengguna
    if (validInput)
    {
        // Lakukan bubble sort untuk mengurutkan array
        bubbleSort(arr, n);

        // Tampilkan hasilnya ke layar
        printf("\nUrutan bilangan dari nilai terkecil sampai terbesar\n");
        displayArray(arr, n);
    }

    return 0;
}
