#include <unistd.h>
#include <stdio.h>

void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void swap(int * arr, int i, int j);

int main(int argc, char *argv[])
{
    int arr [10] = {12, 42, 43, 43, 55, 6, 37, 88, 19, 10};
    int length = (sizeof(arr) / sizeof(arr[0])) - 1;
    quicksort(arr, 0, length);
    for(int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]), "\n";
        printf("\n");
    }
    return 0;
}
void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}
int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}
void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
