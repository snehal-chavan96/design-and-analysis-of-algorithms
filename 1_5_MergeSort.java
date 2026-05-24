import java.util.Scanner;

public class MergeSort {
    private int[] arr = new int[100];
    private int n;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter number of elements: ");
        n = sc.nextInt();

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
    }

    public void merge(int low, int mid, int high) {
        int[] temp = new int[100];

        int i = low;
        int j = mid + 1;
        int k = low;

        // Merge two sorted halves
        while (i <= mid && j <= high) {
            if (arr[i] < arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements from left half
        while (i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }

        // Copy remaining elements from right half
        while (j <= high) {
            temp[k] = arr[j];
            j++;
            k++;
        }

        // Copy back to original array
        for (i = low; i <= high; i++) {
            arr[i] = temp[i];
        }
    }

    public void mergeSort(int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;

            // Left half
            mergeSort(low, mid);

            // Right half
            mergeSort(mid + 1, high);

            // Merge halves
            merge(low, mid, high);
        }
    }

    public void sortArray() {
        mergeSort(0, n - 1);
    }

    public void display() {
        System.out.println("\nSorted array:");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        MergeSort ms = new MergeSort();
        ms.getData();
        ms.sortArray();
        ms.display();
    }
}
