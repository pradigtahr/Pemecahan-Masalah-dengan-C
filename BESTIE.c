#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 255
#define MAX_PEOPLE 3

typedef struct person {
    char nama[MAX_STRING];
    int makanan;
    int minuman;
    int film;
} person;

void getData(person *ptr) {
    for (int i = 0; i < MAX_PEOPLE; ++i) {
        printf("Masukkan nama dan preferensi dengan urut (makanan, minuman, film): ");
        scanf("%s %d %d %d", (ptr + i)->nama, &(ptr + i)->makanan, &(ptr + i)->minuman, &(ptr + i)->film);
    }
}

int calculateDifference(int a, int b) {
    return abs(a - b);
}

void getBestie(person *ptr) {
    int min_diff = calculateDifference((ptr + 0)->makanan, (ptr + 1)->makanan)
                 + calculateDifference((ptr + 0)->minuman, (ptr + 1)->minuman)
                 + calculateDifference((ptr + 0)->film, (ptr + 1)->film);

    int bestie_1 = 0;
    int bestie_2 = 1;

    for (int i = 0; i < MAX_PEOPLE; i++) {
        for (int j = i + 1; j < MAX_PEOPLE; j++) {
            int total_diff = calculateDifference((ptr + i)->makanan, (ptr + j)->makanan)
                           + calculateDifference((ptr + i)->minuman, (ptr + j)->minuman)
                           + calculateDifference((ptr + i)->film, (ptr + j)->film);

            if (total_diff < min_diff) {
                min_diff = total_diff;
                bestie_1 = i;
                bestie_2 = j;
            }
        }
    }

    // Print the names of the besties
    printf("Bestie: %s %s\n", (ptr + bestie_1)->nama, (ptr + bestie_2)->nama);
}



int main(void) {
    person *bestie;
    bestie = (person *)malloc(MAX_PEOPLE * sizeof(person));

    if (bestie == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    getData(bestie);
    getBestie(bestie);

    free(bestie);
    return 0;
}
