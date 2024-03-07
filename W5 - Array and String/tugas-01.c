#include <stdio.h>

void ketik(int array[10]){
    for (int i = 0; i < 10; i++){
        printf("Masukkan nilai ke-%d: ", i+1);
        scanf("%d", &array[i]);
    }
}

void rerata(int rerataArray[10], int *rerataHasil){
    int i, sum = 0;
    for (i = 0; i < 10; i++){
        sum += rerataArray[i];
    }
    *rerataHasil = sum/10;
}

void nbesar(int nbesarN, int nbesarArray[10]){
    // Sorting array dari nbesarArray dengan bubble sort
    int i, j, temp, min;
    for (i = 0; i < 10; i++){
        min = nbesarArray[i];
        for (j = i + 1; j < 10; j++){
            if (nbesarArray[j]<min){
                temp = nbesarArray[i];
                nbesarArray[i] = nbesarArray[j];
                nbesarArray[j] = temp;
            }
        }
    }
    printf("\nHasil diurutkan: ");
    for (i = 0; i < 10; i++) printf("%d ", nbesarArray[i]);
    printf("\n%d nilai terbesar ", nbesarN);
    for (i = 0; i < nbesarN; i++) printf("%d ", nbesarArray[9-i]);

}


int main(void){
    int arr[10], mainHasil;

    ketik(arr);
    rerata(arr, &mainHasil);
    printf("Rata-rata hasil: %d", mainHasil);
    nbesar(3, arr);


    return 0;
}