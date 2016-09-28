import java.util.Arrays;

public class QuickSort {
    public static int[] numbers;

    //Method to swap the 2 integers at indices a and b
    public static void swap(int a, int b){
        int tmp = numbers[a];
        numbers[a] = numbers[b];
        numbers[b] = tmp;
    }

    /*
        Helper function to quickSort. Rearranges the array in such
        a way where there exists a pivot and everything to the left
        of it is smaller and everything to the right of it is larger
     */
    public static int partition(int left, int right){

        //Makes the pivot the rightmost element of the array, start
        //the pivot index from the beginnging
        int pIndex = left, pValue = numbers[right];

        for (int i = left; i <= right - 1; i++){
            if (numbers[i] < pValue){
                swap(i, pIndex);
                pIndex++;
            }
        }

        //Finally place the pivot value with the appropriate index
        swap(pIndex, right);

        return pIndex;
    }

    /*
        The recursive for quick sort. Each function call will choose
        a pivot in the range of [left, right] as p.

        The method will then try to sort the left side and right side
        of the pivot namely [left, p - 1] and [p + 1, right].
     */
    public static void quickSort(int left, int right){
        //If the range only contains <1 elements, it does not need
        //to be sorted
        if (left >= right) return;

        int pivotIndex = partition(left, right);
        quickSort(left, pivotIndex - 1);
        quickSort(pivotIndex + 1, right);
    }

    public static void main(String[] args){
        //The array to be sorted
        numbers = new int[] {7, 2, 1, 6, 8, 5, 3, 4};
        quickSort(0, numbers.length - 1);

        //Print out the results
        System.out.println(Arrays.toString(numbers));
    }
}

