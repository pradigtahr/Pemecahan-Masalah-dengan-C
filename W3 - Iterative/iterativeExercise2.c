#include <stdio.h>
#define X_STEP 0.005           // Partisi, bisa diubah-ubah sesuai dengan tingkat ketelitian yang diinginkan.
#define ACTUAL_VAL 1572.667     // Hasil perhitungan manual

/* RIEMANN SUM*/
int main(void)
{
    /* Deklarasi variabel dan nilai pada kondisi awal */
    double sum, x_last, i, galat;
    sum = 0;        // Var penyimpan jumlahan
    x_last = 10;    // Nilai akhir
    i = 3;          // Nilai awal

    /* Penghitungan luas dibawah kurva f(x) dengan menggunakan pendekatan deret riemann */
    while (i <= x_last)
    {
        sum += (5*i*i - 7)*X_STEP;
        i += X_STEP;
    }

    /* Perhitungan galat */
    galat = (sum-ACTUAL_VAL)/ACTUAL_VAL * 100;

    if (galat < 0)
    {
        galat *= (-1);
    }

    /* Menampilkan hasil perhitungan dan galat */
    printf("Hasil jumlahan riemann  : %.3f\n", sum);
    printf("Galat perhitungan       : %.3f persen.\n", galat);

    return 0;
}