import java.util.Scanner;

public class SumOfSubsets {
    private int[] w = new int[20];
    private int[] x = new int[20];
    private int n, target;
    private Scanner sc = new Scanner(System.in);

    public void input() {
        System.out.print("Enter number of elements: ");
        n = sc.nextInt();

        System.out.println("Enter elements in increasing order:");
        for (int i = 0; i < n; i++) {
            w[i] = sc.nextInt();
        }

        System.out.print("Enter target sum: ");
        target = sc.nextInt();
    }

    public void printSubset() {
        System.out.print("Subset Found = { ");
        for (int i = 0; i < n; i++) {
            if (x[i] == 1)
                System.out.print(w[i] + " ");
        }
        System.out.println("}");
    }

    public void sumOfSubsets(int s, int k, int r) {
        System.out.println("\nCurrent Sum = " + s + ", Current Element = " + w[k] + ", Remaining Sum = " + r);

        // Include current element
        x[k] = 1;
        System.out.println("-> Including " + w[k]);

        if (s + w[k] == target) {
            printSubset();
        } else if (k + 1 < n && s + w[k] + w[k + 1] <= target) {
            sumOfSubsets(s + w[k], k + 1, r - w[k]);
        }

        // Exclude current element
        if (k + 1 < n &&
            (s + r - w[k] >= target) &&
            (s + w[k + 1] <= target)) {

            x[k] = 0;
            System.out.println("-> Excluding " + w[k]);
            sumOfSubsets(s, k + 1, r - w[k]);
        }
    }

    public void solve() {
        int total = 0;

        for (int i = 0; i < n; i++)
            total += w[i];

        System.out.println("\nSteps of Branch and Bound:");
        sumOfSubsets(0, 0, total);
    }

    public static void main(String[] args) {
        SumOfSubsets s = new SumOfSubsets();
        s.input();
        s.solve();
    }
}
