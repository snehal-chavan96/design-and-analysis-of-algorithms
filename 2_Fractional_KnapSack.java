import java.util.Scanner;

public class FractionalKnapsack {
    private static class Item {
        int weight;
        int profit;
        float ratio;

        Item(int weight, int profit) {
            this.weight = weight;
            this.profit = profit;
            this.ratio = (float) profit / weight;
        }
    }

    private Item[] item = new Item[100];
    private int n, capacity;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter number of items: ");
        n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.print("\nEnter weight of item " + (i + 1) + ": ");
            int weight = sc.nextInt();

            System.out.print("Enter profit of item " + (i + 1) + ": ");
            int profit = sc.nextInt();

            item[i] = new Item(weight, profit);
        }

        System.out.print("\nEnter knapsack capacity: ");
        capacity = sc.nextInt();
    }

    public void sortItems() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (item[i].ratio < item[j].ratio) {
                    Item temp = item[i];
                    item[i] = item[j];
                    item[j] = temp;
                }
            }
        }
    }

    public void fractionalKnapsack() {
        sortItems();

        float totalProfit = 0.0f;
        int remaining = capacity;

        System.out.println("\nSelected items:");

        for (int i = 0; i < n; i++) {
            if (item[i].weight <= remaining) {
                System.out.println("Item with weight " + item[i].weight + " and profit " + item[i].profit + " taken completely.");
                remaining -= item[i].weight;
                totalProfit += item[i].profit;
            } else {
                float fraction = (float) remaining / item[i].weight;
                System.out.println("Fraction " + fraction + " of item with weight " + item[i].weight + " taken.");
                totalProfit += item[i].profit * fraction;
                break;
            }
        }

        System.out.println("\nMaximum Profit = " + totalProfit);
    }

    public static void main(String[] args) {
        FractionalKnapsack k = new FractionalKnapsack();
        k.getData();
        k.fractionalKnapsack();
    }
}
