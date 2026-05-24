import java.util.Scanner;

public class CoinChange {
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

        System.out.print("Enter amount to pay: ");
        amount = sc.nextInt();
    }

    public void sortCoins() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (coins[i] < coins[j]) {
                    int temp = coins[i];
                    coins[i] = coins[j];
                    coins[j] = temp;
                }
            }
        }
    }

    public void coinChange() {
        sortCoins();

        int count = 0;
        System.out.println("\nCoins used:");

        for (int i = 0; i < n; i++) {
            while (amount >= coins[i]) {
                amount = amount - coins[i];
                System.out.print(coins[i] + " ");
                count++;
            }
        }

        System.out.println("\n\nMinimum number of coins = " + count);
    }

    public static void main(String[] args) {
        CoinChange c = new CoinChange();
        c.getData();
        c.coinChange();
    }
}
