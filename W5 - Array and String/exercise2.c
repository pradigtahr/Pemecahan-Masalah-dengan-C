#include <stdio.h>
#define ARRSIZ 3

void add_arrays(const double arr1[], const double arr2[], double arrsum[], int n){
    for (int i = 0; i < n; i++){
        arrsum[i] = arr1[i] + arr2[i];
    }
}

int main(void){

    double  arr1[ARRSIZ] = {1, 2, 3},
            arr2[ARRSIZ] = {4, 5, 6},
            arrsum[ARRSIZ]; 

    add_arrays(arr1, arr2, arrsum, ARRSIZ);
    for (int i = 0; i < ARRSIZ; i++){
        printf("%.2f, ", arrsum[i]);
    }

    return 0;
}