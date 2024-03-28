#include <stdio.h>
#include <string.h>

typedef struct Complex{
    int real;
    int imaginer;
} complex;

void ampScaling(complex x, int i, complex *res){
    res-> real = x.real*i;
    res-> imaginer = x.imaginer*i;
}

int main(void){
    complex c[5], result;

    printf("Masukkan bilangan real ke-1: ");
    scanf("%d", &c[0].real);
    printf("Masukkan bilangan imajiner ke-1: ");
    scanf("%d", &c[0].imaginer);

    printf("Nilai bilangan ke-1 adalah: %d + %di\n\n", c[0].real, c[0].imaginer);

    ampScaling(c[0], 10, &result);
    printf("Result of amplitude scaling:\n%d + %di", result.real, result.imaginer);

    return 0;
}