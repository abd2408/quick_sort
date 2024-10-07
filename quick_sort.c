#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int arr[], int l)
{
    for (int i = 0; i <= l; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void fill(int arr[], int l)
{
    for (int i = 0; i < l; i++)
    {
        arr[i] = rand() % 100;
    }
}

int pivot_index(int arr[], int min, int l)
{
    int k = -1;
    int a = arr[l];
    for (int i = min; i < l; i++)
    {
        if (arr[i] <= a)
        {
            k++;
            int t = arr[i];
            arr[i] = arr[k];
            arr[k] = t;
        }
    }
    int t = arr[k + 1];
    arr[k + 1] = arr[l];
    arr[l] = t;
    return k + 1;
}
void sort(int arr[], int min, int pi)
{
    if (min < pi)
    {
        int pivot_i = pivot_index(arr, 0, pi);
        sort(arr, min, pivot_i - 1);
        sort(arr, pivot_i + 1, pi);
    }
}

int main()
{
    // system("cls");
    srand(time(NULL));
    int l;
    printf("Arrayda nechta son bo'lsin: ");
    scanf("%d", &l);
    int arr[l];
    fill(arr, l);
    print(arr, l - 1);
    sort(arr, 0, l - 1);
    print(arr, l - 1);
    return 0;
}