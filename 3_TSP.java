import java.util.Scanner;

public class TSPDivideAndConquer {
    private int[][] graph = new int[10][10];
    private int[] visited = new int[10];
    private int n;
    private int minCost = Integer.MAX_VALUE;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter number of cities: ");
        n = sc.nextInt();

        System.out.println("\nEnter cost matrix:");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = sc.nextInt();
            }
        }
    }

    public void tsp(int city, int count, int cost) {
        // All cities visited
        if (count == n && graph[city][0] > 0) {
            minCost = Math.min(minCost, cost + graph[city][0]);
            return;
        }

        // Visit next city
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && graph[city][i] > 0) {
                visited[i] = 1;
                tsp(i, count + 1, cost + graph[city][i]);
                visited[i] = 0;
            }
        }
    }

    public void solve() {
        // Initialize visited array
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }

        visited[0] = 1;
        tsp(0, 1, 0);

        System.out.println("\nMinimum Travelling Cost = " + minCost);
    }

    public static void main(String[] args) {
        TSPDivideAndConquer t = new TSPDivideAndConquer();
        t.getData();
        t.solve();
    }
}
