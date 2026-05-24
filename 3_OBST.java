import java.util.Scanner;

public class OBST {
    private int n;
    private float[] p = new float[20];
    private float[] q = new float[20];
    private float[][] cost = new float[20][20];
    private float[][] weight = new float[20][20];
    private int[][] root = new int[20][20];
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter number of keys: ");
        n = sc.nextInt();

        System.out.println("\nEnter successful search probabilities:");
        for (int i = 1; i <= n; i++) {
            p[i] = sc.nextFloat();
        }

        System.out.println("\nEnter unsuccessful search probabilities:");
        for (int i = 0; i <= n; i++) {
            q[i] = sc.nextFloat();
        }
    }

    public void constructOBST() {
        // Initialize all matrices
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                cost[i][j] = 0;
                weight[i][j] = 0;
                root[i][j] = 0;
            }
        }

        // Base condition
        for (int i = 0; i <= n; i++) {
            cost[i][i] = 0;
            weight[i][i] = q[i];
        }

        // Length of subtree
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len;
                cost[i][j] = 9999;

                // Calculate weight
                weight[i][j] = weight[i][j - 1] + p[j] + q[j];

                // Find optimal root
                for (int r = i + 1; r <= j; r++) {
                    float c = cost[i][r - 1] + cost[r][j] + weight[i][j];

                    // Minimum cost
                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                        root[i][j] = r;
                    }
                }
            }
        }

        display();
    }

    public void display() {
        System.out.println("\nCost Matrix:\n");

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                System.out.printf("%8.1f ", cost[i][j]);
            }
            System.out.println();
        }

        System.out.println("\nRoot Matrix:\n");

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                System.out.printf("%5d ", root[i][j]);
            }
            System.out.println();
        }

        System.out.println("\nMinimum Expected Cost = " + cost[0][n]);
    }

    public static void main(String[] args) {
        OBST o = new OBST();
        o.getData();
        o.constructOBST();
    }
}
