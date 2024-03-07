#include <stdio.h>
#include <stdlib.h>

int reverse(int number){
    int reversedNum = 0, 
        remainder;

    while(number != 0){
        remainder = number % 10;
        reversedNum = reversedNum * 10 + remainder;
        number /= 10;
    }

    return reversedNum;

}

void primeFactors(int num){
    // Cetak semua angka dua yang bisa membagi num
    int c = 2;
    while (num > 1){
        if (num % c == 0){
            if (c != num){
                printf("%d x ", c);
            }
            else{
                printf("%d", c);
            }
            num /= c;
        }
        else{
            c++;
        }
    }
}

int main(void){
    int a, b, c;

    int is_A_zero = 1, is_B_zero = 1;
    while (is_A_zero){
        printf("Masukkan bilangan A: ");
        scanf("%d", &a);
        if (a != 0){
            is_A_zero = 0;
        }
        else{
            printf("\nBilangan yang anda masukkan bernilai 0\n");
        }
    }

    while (is_B_zero){
        printf("Masukkan bilangan B: ");
        scanf("%d", &b);
        if (b != 0){
            is_B_zero = 0;
        }
        else{
            printf("\nBilangan yang anda masukkan bernilai 0\n");
        }
    }

    int a_reversed, b_reversed;
    a_reversed = reverse(a);
    b_reversed = reverse(b);

    c = a_reversed + b_reversed;
    printf("\nBilangan C adalah %d\n", c);

    printf("Faktorisasi prima dari %d = ", c);
    primeFactors(c);


    return 0;
}