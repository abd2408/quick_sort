#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("%d\t", arr[i]);
    }
} 

void q(int arr[], int i, int l){
    int a = arr[l]; // a = 0
    for (int k = i - 1; i <= l; i++){
        if (arr[i] <= a){
            if (arr[i] == a && i != l){
                k--;
            }
            k++;
            if (k == i){
                continue;
            }
            else if (k < i){
                int swap = arr[i];
                arr[i] = arr[k];
                arr[k] = swap;
            }
        }
    }
    for (int i = 0; i <= l; i++){
        if (arr[i] == a && i != 0 && i != l){
            q(arr, 0, i - 1);
            q(arr, i + 1, l);
        }
        else if (i == l && arr[i] == a){
            q(arr, 0, l - 1);
        }
        else if (i == 0 && arr[i] == a){
            q(arr, 1, l);
        }
    }
}

int main() {
    system("cls");
    
    int arr[] = {3,7,4,9,0,1,5,2,8};
    int l = sizeof(arr) / sizeof(arr[0]);
    q(arr, 0, l-1);
    print(arr, l);
}