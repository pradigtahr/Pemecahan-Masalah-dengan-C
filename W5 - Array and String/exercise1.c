#include <stdio.h>

void gt_70(int arr[5], char nama[5][5]){
    for (int i = 0; i < 5; i++){
        if (arr[i] > 70){
            printf("%d\t: ", arr[i]);
            printf("%s\n", nama[i]);
        }
    }
}

void sum_gt_70(int arr[5], int *sum){
    for (int i = 0; i < 5; i++){
        if (arr[i] > 70){
            *sum += 1;
        }
    }
}

int main(void){

    int arr[5] = {30, 80, 70, 100, 0};
    char nama[5][5] = {"Anto", "Budi", "Candi", "Dewi", "Edwin"};
    int sum = 0;

    printf("Nilai di atas 70:\n");
    gt_70(arr, nama);

    sum_gt_70(arr, &sum);
    printf("\nBanyak nilai di atas 70: %d orang.", sum);


    return 0;
}