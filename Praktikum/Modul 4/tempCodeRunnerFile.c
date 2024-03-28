void decryptMessage(char *s, int key){
    // Cek huruf satu per satu
    // basis
    if (*s){
        int ch = *s;
        ch = (ch - 'a' - key + 26) % 26 + 'a'; 
        encryptMessage(s + 1, key);
    }
    else{
        printf("Pesan yang didekripsi: %s", s);
    }
}