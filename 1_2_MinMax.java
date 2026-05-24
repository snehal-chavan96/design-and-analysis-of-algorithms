import java.util.Scanner;

public class MinMax {
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

    public int[] findMinMax(int low, int high) {
        int[] result = new int[2]; // [min, max]
        int mid;
        int[] min1max1;
        int[] min2max2;

        if (low == high) {
            result[0] = arr[low];
            result[1] = arr[low];
        } else if (high == low + 1) {
            result[0] = Math.min(arr[low], arr[high]);
            result[1] = Math.max(arr[high], arr[low]);
        } else {
            mid = (low + high) / 2;

            min1max1 = findMinMax(low, mid);
            min2max2 = findMinMax(mid + 1, high);

            result[0] = Math.min(min1max1[0], min2max2[0]);
            result[1] = Math.max(min1max1[1], min2max2[1]);
        }

        return result;
    }

    public void display() {
        int[] result = findMinMax(0, n - 1);
        System.out.println("\nMinimum element = " + result[0]);
        System.out.println("Maximum element = " + result[1]);
    }

    public static void main(String[] args) {
        MinMax m = new MinMax();
        m.getData();
        m.display();
    }
}
