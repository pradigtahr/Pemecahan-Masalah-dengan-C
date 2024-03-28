// Pradigta Hisyam Ramadhan 
// 18322008

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    int age;
    float weight;
    char name[30];
} person;

void isiData(int n, person *ptr) {
    for (int i = 0; i < n; ++i) {
        printf("Enter first name and age respectively: ");
        scanf("%s %d", (ptr + i)->name, &(ptr + i)->age);
    }
}

void getUserChoice(int *choice){
    printf("\n1. Ubah data\n2. Hapus data\n");
    printf("Pilih mode untuk mengedit data: ");
    scanf("%d", choice);
}


void ubahData(int n, person *ptr) {
    person replacePerson, newPerson;
    printf("Masukkan nama dan usia yang ingin diubah: ");
    scanf("%s %d", replacePerson.name, &replacePerson.age);
    printf("Masukkan nama dan usia yang baru: ");
    scanf("%s %d", newPerson.name, &newPerson.age);

    // ubah namanya
    for (int i = 0; i < n; ++i) {
        if (strcmp((ptr + i)->name, replacePerson.name) == 0 && (ptr + i)->age == replacePerson.age) {
            strcpy((ptr + i)->name, newPerson.name);
            (ptr + i)->age = newPerson.age;
            return;
        }
    }
    printf(">> Nama tidak tercatat");
}

void hapusData(int n, person *ptr){
    person deletePerson;
    printf("Masukkan nama dan usia yang ingin dihapus: ");
    scanf("%s %d", deletePerson.name, &deletePerson.age);

    //hapus namanya
    for (int i=0; i<n; ++i){
        if (strcmp((ptr+i)->name, deletePerson.name) == 0 && (ptr+i)->age == deletePerson.age){
            strcpy((ptr+i)->name, "\0");
            (ptr+i)->age = 0;
            return;
        }
    }
    printf(">> Nama tidak tecatat");
}

int main() {
    person *ptr;
    int n, choice;

    printf("Enter the number of persons: ");
    scanf("%d", &n);

    // allocating memory for n numbers of struct person
    ptr = (person *)malloc(n * sizeof(person));

    isiData(n, ptr);

    // Display menu to process data
    choice = 69;
    while (choice!=0){
        getUserChoice(&choice);
        if (choice == 1){
            ubahData(n, ptr);
        }
        else if (choice == 2){
            hapusData(n, ptr);
        }
    }

    printf("\nDisplaying Information:\n");
    for (int i = 0; i < n; ++i)
        printf("Name: %s\tAge: %d\n", (ptr + i)->name, (ptr + i)->age);

    free(ptr); // bebaskan memory
    return 0;
}
