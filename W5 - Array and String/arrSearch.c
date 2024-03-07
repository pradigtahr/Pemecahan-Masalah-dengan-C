#include <stdio.h>
#include <string.h>

void getValue(char nama[5][7], int nilai[5]){
    for (int i = 0; i < 5; i++){
        printf("Masukkan nilai %s:\t", nama[i]);
        scanf("%d", &nilai[i]);
    }
}

void get_max_val(int nilai[5], int *max){
    *max = nilai[0];
    for (int i = 1; i < 5; i++){
        if (*max < nilai[i]){
            *max = nilai[i];
        }
    }
}

void getPerson(char nama[5][7], int nilai[5], int maximum_val, char person[7]){
    for (int i = 0; i < 5; i++){
        if (nilai[i] == maximum_val){
            strcpy(person, nama[i]);
            break;
        }
    }
}

int main(void){

    char    nama[5][7] = {"Anton", "Bhima", "Cinta", "Daris", "Edith"};
    int     nilai[5];
    int     max;
    char    person[7];  // Corrected size

    // Input nilai
    getValue(nama, nilai);

    get_max_val(nilai, &max);

    printf("\nNilai tertinggi\t\t: %d\n", max);

    getPerson(nama, nilai, max, person);
    printf("Orang yang meraih\t: %s\n", person);

    return 0;
}
