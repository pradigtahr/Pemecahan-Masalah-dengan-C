#include <stdio.h>
#include <string.h>

void getValue(int uts, int uas, int kuis, int pr, double *nilaiAkhir, char *grade)
{
    // Hitung nilai akhir
    *nilaiAkhir = (0.25 * uts) + (0.3 * uas) + (0.2 * kuis) + (0.25 * pr);

    // Tentukan indeks mahasiswa
    if (*nilaiAkhir >= 90)
    {
        *grade = 'A';
    }
    else if (*nilaiAkhir >= 80)
    {
        *grade = 'B';
    }
    else if (*nilaiAkhir >= 70)
    {
        *grade = 'C';
    }
    else
    {
        *grade = 'D';
    }
}

void insertNilai(char komponen1[6], char komponen2[6], char komponen3[6], char komponen4[6],
                 int nilai1, int nilai2, int nilai3, int nilai4, int *keyValue, char key[6])
{
    if (nilai1 >= 0 || nilai2 >= 0 || nilai3 >= 0 || nilai4 >= 0)
    {
        if (strcmp(komponen1, key) == 0)
        {
            *keyValue = nilai1;
        }
        else if (strcmp(komponen2, key) == 0)
        {
            *keyValue = nilai2;
        }
        else if (strcmp(komponen3, key) == 0)
        {
            *keyValue = nilai3;
        }
        else if (strcmp(komponen4, key) == 0)
        {
            *keyValue = nilai4;
        }
    }
}

int main(void)
{
    char komponen1[6], komponen2[6], komponen3[6], komponen4[6];
    int nilai1, nilai2, nilai3, nilai4;
    int uts, uas, kuis, pr;
    double na;
    char idx;

    printf("Masukkan nilai: \n");
    scanf("%s%d%s%d%s%d%s%d", komponen1, &nilai1, komponen2, &nilai2, komponen3, &nilai3, komponen4, &nilai4);
    printf("%s: %d\n", komponen1, nilai1);

    insertNilai(komponen1, komponen2, komponen3, komponen4, nilai1, nilai2, nilai3, nilai4, &uts, "uts");
    insertNilai(komponen1, komponen2, komponen3, komponen4, nilai1, nilai2, nilai3, nilai4, &uas, "uas");
    insertNilai(komponen1, komponen2, komponen3, komponen4, nilai1, nilai2, nilai3, nilai4, &kuis, "kuis");
    insertNilai(komponen1, komponen2, komponen3, komponen4, nilai1, nilai2, nilai3, nilai4, &pr, "pr");

    // Hitung nilai akhir dan indeks
    getValue(uts, uas, kuis, pr, &na, &idx);

    printf("NA: %.3f\nIndeks: %c\n", na, idx);
    return 0;
}
