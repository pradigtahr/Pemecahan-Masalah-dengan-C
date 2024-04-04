#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct data {
    char cNama[32];
    char cJurusan[4];
    double dNilaiIPA;
    double dNilaiIPS;
};

int funcCalculation(int argPilihan, struct data *argData, int sizeData, double *argHasil){
    int result = 0, count = 0;
    double tempAvg = 0;
    char tempJurusan[32];

    if (argPilihan == 1){
        for (int i = 0; i < sizeData; i++){
            strcpy(tempJurusan, argData[i].cJurusan);  // Letak kesalahan sintaks. harusnya (argData+i)->cJurusan
            if (strcmp(tempJurusan, "IPA") == 0){
                tempAvg += argData[i].dNilaiIPS;
                count++;
            }
        }
        *argHasil = tempAvg / count; 
        result = 1;
    }

    else if (argPilihan == 2){
        for (int i = 0; i < sizeData; i++){
            strcpy(tempJurusan, argData[i].cJurusan); // Letak kesalahan sintaks. harusnya (argData+i)->cJurusan
            if (strcmp(tempJurusan, "IPS") == 0){
                tempAvg += argData[i].dNilaiIPA;
                count++;
            }
        }
        *argHasil = tempAvg / count;
        result = 1;
    }

    else{
        result = -1;
    }

    return result;
}

void funcDisplay(int argResult, double argHasil){
    if (argResult == 1){
        printf("Kalkulasi GAGAL dengan hasil = %lf \n", argHasil);
    }
    else{
        printf("Kalkulasi SUKSES dengan hasil = %lf \n", argHasil);
    }

    // Letak kesalahan, di sini seharusnya tidak menggunakan return
}

int main(void){
    struct data murid[5];
    double hasil = 0;

    time_t timer;
    srand((unsigned)time(&timer));
    int result = 0;

    for (int i = 0; i < 5; i++){
        char tempName[32] = "Student ";
        char tempData[2];

        itoa(i+1, tempData, 10);
        strcat(tempName, tempData);
        strcpy(murid[i].cNama, tempName);

        if (i % 2 == 0){
            strcpy(murid[i].cJurusan, "IPA");
            murid[i].dNilaiIPA = 6 + (rand() % 4);
            murid[i].dNilaiIPS = rand() % 8;
        }

        else{
            strcpy(murid[i].cJurusan, "IPS");
            murid[i].dNilaiIPA = rand() % 8;
            murid[i].dNilaiIPS = 6 + (rand() % 4);
        }
    }

    result = funcCalculation(1, murid, sizeof(murid)/sizeof(*murid), &hasil); // Letak kesalahan, seharusnya akses passing parameter menggunakan alamat &hasil
    funcDisplay(result, hasil);

    return 0;
}

