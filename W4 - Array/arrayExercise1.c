#include <stdio.h>



int main(void)
{
    // Deklarasi variabel
    int A[8] = {1, 8, 3, 2, 2, 0, 0, 8},
        i, j, minIndex, temp;

    // Sort angka berdasarkan urutan dari kecil ke terbesar
    for (i = 0; i < 8 - 1; i++)
    {
        // Asumsi indeks ke-i adalah nilai minimum
        minIndex = i;

        // Mencari indeks untuk nilai minimum di array
        for (j = i + 1; j < 8; j++)            // Ditambah 1 karena indeks sebelumnya tidak dipakai.
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }

    // Print NIM terurut
    printf("NIM terurut: ");
    for (i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
