#include <unistd.h>
#include <stdio.h>

void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void swap(int * arr, int i, int j);

int main(int argc, char *argv[])
{
    int arr [8] = {34, 23, 12, 3, 4, 5, 1, 0};
    int length = (sizeof(arr) / sizeof(arr[0])) - 1;
    quicksort(arr, 0, length);
    for(int i = 0; i < length + 1; i++)
    {
        printf("%d", arr[i]), "\n";
        printf("\n");
    }
    return 0;
}
void quicksort(int *arr, int low, int high)
{
    if(high == 0 || high == -1){
        return;
    }
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}
int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = high + 1;
    for (int j = high; j >= low + 1; j--)
    {
        if (arr[j] >= pivot)
        {
            i--;
            swap(arr, i, j);
        }
    }
    swap(arr, i - 1, low);
    return i - 1;
}
void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
