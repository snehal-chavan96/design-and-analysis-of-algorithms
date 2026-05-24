import java.util.Scanner;
import java.util.Arrays;

public class TSPBranchAndBound {

    private static final int N = 4;

    private int[][] graph = new int[N][N];
    private int[] finalPath = new int[N + 1];
    private boolean[] visited = new boolean[N];
    private int finalCost = Integer.MAX_VALUE;

    private Scanner sc = new Scanner(System.in);

    // Input graph
    public void getGraph() {
        System.out.println("Enter Cost Matrix:");

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                graph[i][j] = sc.nextInt();
            }
        }
    }

    // Find minimum edge cost from city i
    public int firstMin(int i) {
        int min = Integer.MAX_VALUE;

        for (int k = 0; k < N; k++) {
            if (i != k && graph[i][k] < min) {
                min = graph[i][k];
            }
        }

        return min;
    }

    // Find second minimum edge cost from city i
    public int secondMin(int i) {
        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;

        for (int j = 0; j < N; j++) {

            if (i == j)
                continue;

            if (graph[i][j] <= first) {
                second = first;
                first = graph[i][j];
            }
            else if (graph[i][j] < second &&
                     graph[i][j] != first) {
                second = graph[i][j];
            }
        }

        return second;
    }

    // Recursive Branch and Bound function
    public void tspRec(int currBound,
                       int currWeight,
                       int level,
                       int[] currPath) {

        // Base case: all cities visited
        if (level == N) {

            // Check if there is an edge back to start
            if (graph[currPath[level - 1]][currPath[0]] != 0) {

                int currRes = currWeight +
                        graph[currPath[level - 1]][currPath[0]];

                // Update final result
                if (currRes < finalCost) {

                    for (int i = 0; i < N; i++) {
                        finalPath[i] = currPath[i];
                    }

                    finalPath[N] = currPath[0];
                    finalCost = currRes;
                }
            }

            return;
        }

        // Try all possible next cities
        for (int i = 0; i < N; i++) {

            if (graph[currPath[level - 1]][i] != 0 &&
                    !visited[i]) {

                int temp = currBound;

                currWeight += graph[currPath[level - 1]][i];

                // Compute new bound
                if (level == 1) {
                    currBound -= (
                            (firstMin(currPath[level - 1]) +
                             firstMin(i)) / 2
                    );
                }
                else {
                    currBound -= (
                            (secondMin(currPath[level - 1]) +
                             firstMin(i)) / 2
                    );
                }

                // If promising
                if (currBound + currWeight < finalCost) {

                    currPath[level] = i;
                    visited[i] = true;

                    tspRec(currBound,
                           currWeight,
                           level + 1,
                           currPath);
                }

                // Backtrack
                currWeight -= graph[currPath[level - 1]][i];
                currBound = temp;

                // Reset visited array correctly
                Arrays.fill(visited, false);

                for (int j = 0; j <= level - 1; j++) {
                    visited[currPath[j]] = true;
                }
            }
        }
    }

    // Solve TSP
    public void solve() {

        int[] currPath = new int[N + 1];

        Arrays.fill(currPath, -1);

        int currBound = 0;

        // Compute initial lower bound
        for (int i = 0; i < N; i++) {
            currBound += (firstMin(i) + secondMin(i));
        }

        // Round up
        currBound = (currBound % 2 == 1)
                ? currBound / 2 + 1
                : currBound / 2;

        // Start from city 0
        visited[0] = true;
        currPath[0] = 0;

        tspRec(currBound, 0, 1, currPath);

        // Print result
        System.out.println("\nMinimum Cost: " + finalCost);

        System.out.print("Path: ");

        for (int i = 0; i <= N; i++) {
            System.out.print(finalPath[i] + " ");
        }

        System.out.println();
    }

    // Main method
    public static void main(String[] args) {

        TSPBranchAndBound t = new TSPBranchAndBound();

        t.getGraph();

        t.solve();
    }
}