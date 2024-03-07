#include <stdio.h>
#include <string.h>
#define MAX_COMMAND 100

int main(void) {
    int x, y, z, cmdLength;
    char cmd[MAX_COMMAND];

    // Origin points
    x = 0;
    y = 0;
    z = 0;

    printf("Masukkan perintah untuk robot: ");
    scanf("%s", cmd);

    // Cari panjang string
    cmdLength = strlen(cmd);

    for (int i = 0; i < cmdLength; i++) {
        if (cmd[i] == 'F') {
            y += 1;
        } else if (cmd[i] == 'B') {
            y -= 1;
        } else if (cmd[i] == 'R') {
            x += 1;
        } else if (cmd[i] == 'L') {
            x -= 1;
        } else if (cmd[i] == 'U') {
            z += 1;
        } else if (cmd[i] == 'D') {
            z -= 1;
        } else {
            printf("Perintah yang dimasukkan salah!\n");
            return 1;  // Exit with an error code
        }
    }

    // Check if any coordinate is not zero
    if (x != 0 || y != 0 || z != 0) {
        printf("Posisi akhir robot: (%d, %d, %d)\n", x, y, z);
    } 

    return 0;
}
