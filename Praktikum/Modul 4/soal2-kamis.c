#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_STRING 255

// Function prototypes
void displayMenu(void);

int validateChoice(int choice);

char* encryptMessage(char *s, int key, int idx);

char* decryptMessage(char *s, int key, int idx);

int main(void){
    int choice, key;
    char s[MAX_STRING];

    // Tampilkan menu
    displayMenu();

    // Menerima masukan dari user dan divalidasi
    do
    {
        printf("Pilihan: ");
        scanf("%d", &choice);
        // Validasi input
        if (validateChoice(choice)){
            break;
        }
        else{
            printf("Tidak valid\n");
        }
    } while (validateChoice(choice) != 1);

    if (choice == 1){
        printf("Masukkan pesan yang ingin dienkripsi: ");
        scanf("%s", s);
        printf("Masukkan jumlah suara sapi: ");
        scanf("%d", &key);
        char *encrypted_message = encryptMessage(s, key, 0);
        printf("Pesan yang dienkripsi: %s", encrypted_message);
    }
    else{
        printf("Masukkan pesan yang ingin didekripsi: ");
        scanf("%s", s);
        printf("Masukkan jumlah suara sapi: ");
        scanf("%d", &key);
        char *decrypted_message = decryptMessage(s, key, 0);
        printf("Pesan yang didekripsi: %s", decrypted_message);
    }



    return 0;
}

// Function realization
void displayMenu(void){
    printf("Pilih menu\n");
    printf("1. Enkripsi\n");
    printf("2. Dekripsi\n");
}

int validateChoice(int choice){
    if (choice == 1 || choice == 2){
        return 1;
    }
    else{
        return 0;
    }
}

char* encryptMessage(char *s, int key, int idx){   
     // basis
    if (s[idx] == '\0'){
        return s;
    }
    else{
        // Variabel lokal untuk menampung satu karakter
        int ch = s[idx];
        // Asumsi karakter tidak kapital dan selalu menerima pesan tanpa spasi
        ch = (ch - 'a' + key) % 26 + 'a';
        // Gantikan karakter terenkode
        s[idx] = ch;
        // rekuren
        encryptMessage(s, key, ++idx);
    }
}

char* decryptMessage(char *s, int key, int idx){
    // basis
    if (s[idx] == '\0'){
        return s;
    }
    else{
        // Variabel lokal untuk menampung satu karakter
        int ch = s[idx];
        // Asumsi karakter tidak kapital dan selalu menerima pesan tanpa spasi
        ch = (ch - 'a' - key + 26) % 26 + 'a';
        // Gantikan karakter terenkode
        s[idx] = ch;
        // rekuren
        decryptMessage(s, key, ++idx);
    }
}