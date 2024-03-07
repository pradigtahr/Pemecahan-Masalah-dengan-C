#include <stdio.h>

void getValue(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter value number-%d:\t", i+1);
        scanf("%d", arr[i]);
    }
}

void getStatistic(int arr[], int n, int *min, int *max, double *mean)
{
    // Deklarasi nilai awal
    *min = arr[0];
    *max = arr[0];
    int sum = 0;

    for (int i = 1; i < n; i++)
    {
        if (*min < arr[i])
        {
            *min = arr[i];
        }

        if (*max < arr[i])
        {
            *max = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    *mean = sum/n;

}


int main(void)
{
    int arr[5], n=5, maksimum, minimum;
    double rerata;

    getValue(arr, n);

    getStatistic(arr, n, &minimum, &maksimum, &rerata);

    printf("Min: %d\nMax: %d\nMean: %.3f", minimum, maksimum, rerata);

    return 0;
}