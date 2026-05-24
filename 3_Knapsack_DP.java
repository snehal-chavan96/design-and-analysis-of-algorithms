import java.util.Scanner;

public class KnapsackDP {
    private int[] weight = new int[100];
    private int[] profit = new int[100];
    private int[][] dp = new int[100][100];
    private int n, capacity;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter number of items: ");
        n = sc.nextInt();

        System.out.println("\nEnter weights:");
        for (int i = 1; i <= n; i++) {
            weight[i] = sc.nextInt();
        }

        System.out.println("\nEnter profits:");
        for (int i = 1; i <= n; i++) {
            profit[i] = sc.nextInt();
        }

        System.out.print("\nEnter knapsack capacity: ");
        capacity = sc.nextInt();
    }

    public void solveKnapsack() {
        // Initialize table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= capacity; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (weight[i] <= j) {
                    dp[i][j] = Math.max(
                        profit[i] + dp[i - 1][j - weight[i]],
                        dp[i - 1][j]
                    );
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        display();
    }

    public void display() {
        System.out.println("\nDP Table:");

        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                System.out.printf("%4d", dp[i][w]);
            }
            System.out.println();
        }

        System.out.println("\nMaximum Profit = " + dp[n][capacity]);

        // Display selected items
        System.out.println("\nSelected Items:");

        int i = n;
        int w = capacity;

        while (i > 0 && w > 0) {
            // Item was selected
            if (dp[i][w] != dp[i - 1][w]) {
                System.out.println("Item " + i + " (Weight = " + weight[i] + ", Profit = " + profit[i] + ")");
                w = w - weight[i];
            }
            i--;
        }
    }

    public static void main(String[] args) {
        KnapsackDP k = new KnapsackDP();
        k.getData();
        k.solveKnapsack();
    }
}
