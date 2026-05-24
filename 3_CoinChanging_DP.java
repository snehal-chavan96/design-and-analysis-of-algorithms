import java.util.Scanner;

public class CoinChangeDP {
    private int[] coins = new int[100];
    private int n, amount;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter number of coin denominations: ");
        n = sc.nextInt();

        System.out.println("Enter coin denominations:");
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }

        System.out.print("Enter amount: ");
        amount = sc.nextInt();
    }

    public void minCoins() {
        int[][] dp = new int[n + 1][amount + 1];

        // Initialize
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }

        // Base case: 0 coins to make 0 amount
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        // Build DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                // Case 1: don't take coin i-1
                dp[i][j] = dp[i - 1][j];

                // Case 2: take coin i-1 (if possible)
                if (coins[i - 1] <= j) {
                    int subResult = dp[i][j - coins[i - 1]];

                    if (subResult != Integer.MAX_VALUE) {
                        dp[i][j] = Math.min(dp[i][j], subResult + 1);
                    }
                }
            }

            // Print table after each coin row
            for (int j = 0; j <= amount; j++) {
                System.out.print(dp[i][j] + "\t");
            }
            System.out.println();
        }

        // Final answer
        if (dp[n][amount] == Integer.MAX_VALUE) {
            System.out.println("\nAmount cannot be formed.");
        } else {
            System.out.println("\nMinimum coins required = " + dp[n][amount]);
        }
    }

    public static void main(String[] args) {
        CoinChangeDP c = new CoinChangeDP();
        c.getData();
        c.minCoins();
    }
}
