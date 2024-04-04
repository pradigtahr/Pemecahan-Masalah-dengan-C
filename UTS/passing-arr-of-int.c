#include <stdio.h>
#include <stdlib.h>

// Function
void getNum(int *n){
    do {
        printf("Pick the n for number elements: ");
        scanf("%d", n);
        if (*n <= 0){
            printf("Please provide postive value!\n");
        }
    } while (*n <= 0);
}


int* getNumElements(int num_count){
    int* arrNum = (int *)malloc(num_count*sizeof(int));
    for(int i = 0; i < num_count; i++){
        printf("Enter number %d: ", i+1);
        scanf("%d", &arrNum[i]);
    }

    return arrNum;
}

int main(void){

    int *num;
    int n;

    // Input how much the array elements and validate it
    getNum(&n);

    // Input number for each element, then
    num = getNumElements(n);

    // print each line
    for (int i=0; i<n; i++){
        printf("%d ", num[i]);
    }

    return 0;
}