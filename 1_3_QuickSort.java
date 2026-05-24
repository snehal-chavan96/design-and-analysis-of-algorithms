import java.util.Scanner;
import java.util.Arrays;

public class QuickSort {
    private int[] arr = new int[100];
    private int n;
    private int pass = 1;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter number of elements: ");
        n = sc.nextInt();

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
    }

    public void displayArray() {
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public void finalOutput() {
        System.out.println("\nSorted Array:");
        displayArray();
    }

    public int findMedian(int[] a, int size) {
        int[] temp = new int[size];
        System.arraycopy(a, 0, temp, 0, size);
        Arrays.sort(temp);
        return temp[size / 2];
    }

    public int medianOfMedians(int[] a, int size) {
        if (size <= 5) {
            return findMedian(a, size);
        }

        int[] medians = new int[20];
        int i;
        for (i = 0; i < size / 5; i++) {
            int[] temp = new int[5];
            System.arraycopy(a, i * 5, temp, 0, 5);
            medians[i] = findMedian(temp, 5);
        }

        if (i * 5 < size) {
            int remaining = size % 5;
            int[] temp = new int[remaining];
            System.arraycopy(a, i * 5, temp, 0, remaining);
            medians[i] = findMedian(temp, remaining);
            i++;
        }

        int[] medianArray = new int[i];
        System.arraycopy(medians, 0, medianArray, 0, i);
        return medianOfMedians(medianArray, i);
    }

    public int partition(int low, int high) {
        int size = high - low + 1;
        int[] temp = new int[size];

        for (int i = 0; i < size; i++) {
            temp[i] = arr[low + i];
        }

        int pivot = medianOfMedians(temp, size);
        int pvtIdx = -1;

        for (int i = low; i <= high; i++) {
            if (arr[i] == pivot) {
                pvtIdx = i;
                break;
            }
        }

        swap(arr, pvtIdx, high);

        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }

        swap(arr, i + 1, high);
        return i + 1;
    }

    public void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    public void sort() {
        quickSort(0, n - 1);
        finalOutput();
    }

    public static void main(String[] args) {
        QuickSort qs = new QuickSort();
        qs.getData();
        qs.sort();
    }
}
