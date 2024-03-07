#include <stdio.h>

void swapValues(int (*matrix)[5][5][5], int x1, int y1, int z1, int x2, int y2, int z2) {
    // Ensure that the coordinates are within the valid range (0 to 4)
    if (x1 >= 0 && x1 < 5 && y1 >= 0 && y1 < 5 && z1 >= 0 && z1 < 5 &&
        x2 >= 0 && x2 < 5 && y2 >= 0 && y2 < 5 && z2 >= 0 && z2 < 5) {

        // Swap values at the specified coordinates
        int temp = (*matrix)[x1][y1][z1];
        (*matrix)[x1][y1][z1] = (*matrix)[x2][y2][z2];
        (*matrix)[x2][y2][z2] = temp;
    } else {
        // Handle invalid coordinates
        printf("Invalid coordinates.\n");
    }
}

void displayMatrix(int (*matrix)[5][5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                printf("%d\t", (*matrix)[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main(void) {
    int cube[5][5][5] = {{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}},
                        {{26, 27, 28, 29, 30}, {31, 32, 33, 34, 35}, {36, 37, 38, 39, 40}, {41, 42, 43, 44, 45}, {46, 47, 48, 49, 50}},
                        {{51, 52, 53, 54, 55}, {56, 57, 58, 59, 60}, {61, 62, 63, 64, 65}, {66, 67, 68, 69, 70}, {71, 72, 73, 74, 75}},
                        {{76, 77, 78, 79, 80}, {81, 82, 83, 84, 85}, {86, 87, 88, 89, 90}, {91, 92, 93, 94, 95}, {96, 97, 98, 99, 100}},
                        {{101, 102, 103, 104, 105}, {106, 107, 108, 109, 110}, {111, 112, 113, 114, 115}, {116, 117, 118, 119, 120}, {121, 122, 123, 124, 125}}};

    printf("Matrix before swapping:\n");
    displayMatrix(&cube);

    // Perform swaps based on the provided coordinates
    swapValues(&cube, 0, 4, 0, 4, 0, 4);
    swapValues(&cube, 0, 4, 1, 4, 0, 3);
    swapValues(&cube, 0, 4, 2, 4, 0, 2);
    swapValues(&cube, 1, 4, 0, 3, 0, 4);
    swapValues(&cube, 1, 4, 1, 3, 0, 3);
    swapValues(&cube, 2, 4, 0, 2, 0, 4);

    printf("\nMatrix after swapping:\n");
    displayMatrix(&cube);

    return 0;
}
