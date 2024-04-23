getchar();  // mengambil karakter newline dari input sebelumnya
                fgets(nama, MAX_STRING, stdin);
                nama[strcspn(nama, "\n")] = '\0';