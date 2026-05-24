import java.util.Scanner;
import java.util.Random;

public class RandomizedQuickSort {
    private int[] arr = new int[100];
    private int n;
    private Scanner sc = new Scanner(System.in);
    private Random rand = new Random();

    public void getData() {
        System.out.print("Enter number of elements: ");
        n = sc.nextInt();

        System.out.println("Enter array elements:");

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
    }

    public void swap(int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public int partition(int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(i, j);
            }
        }

        swap(i + 1, high);
        return i + 1;
    }

    public int randomizedPartition(int low, int high) {
        int random = low + rand.nextInt(high - low + 1);
        swap(random, high);
        return partition(low, high);
    }

    public void quickSort(int low, int high) {
        if (low < high) {
            int pi = randomizedPartition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    public void display() {
        System.out.println("\nSorted Array:");

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public void start() {
        quickSort(0, n - 1);
        display();
    }

    public static void main(String[] args) {
        RandomizedQuickSort q = new RandomizedQuickSort();
        q.getData();
        q.start();
    }
}
