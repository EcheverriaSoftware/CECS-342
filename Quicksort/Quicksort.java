import java.util.Arrays;

//Link: https://www.geeksforgeeks.org/quick-sort/
public class Quicksort{
    public static void main(String [] args){
        int [] arr = {70, 80, 30, 90, 40, 50, 20};
        int length = arr.length - 1; 
        quicksort(arr, 0, length);
        System.out.println(Arrays.toString(arr));
    }
    public static void quicksort(int [] arr, int low, int high){
        if(low < high){
            int pivot = partition(arr, low, high);
            quicksort(arr, low, pivot - 1);
            quicksort(arr, pivot + 1, high);
        }
    }
    public static int partition(int [] arr, int low, int high){
        int pivot = arr[low];
        int i = high + 1;
        for(int j = high; j >= low + 1; j--){
            if(arr[j] >= pivot){
                i--;
                swap(arr, i, j);
            }
        }
        swap(arr, i - 1, low);
        return i - 1;
    }
    public static void swap(int [] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}