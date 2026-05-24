import java.util.Scanner;

public class MatrixChainMultiplication {
    private int[] p = new int[20];
    private int[][] m = new int[20][20];
    private int n;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter number of matrices: ");
        n = sc.nextInt();

        System.out.println("\nEnter dimensions array:");
        System.out.println("Enter " + (n + 1) + " values:");

        for (int i = 0; i <= n; i++) {
            p[i] = sc.nextInt();
        }
    }

    public void matrixChainOrder() {
        int i, j, k, L, q;

        // Cost is zero for one matrix
        for (i = 1; i <= n; i++) {
            m[i][i] = 0;
        }

        // L = chain length
        for (L = 2; L <= n; L++) {
            for (i = 1; i <= n - L + 1; i++) {
                j = i + L - 1;
                m[i][j] = Integer.MAX_VALUE;

                for (k = i; k < j; k++) {
                    q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                    if (q < m[i][j]) {
                        m[i][j] = q;
                    }
                }
            }
        }

        display();
    }

    public void display() {
        System.out.println("\nCost Matrix:");

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i > j)
                    System.out.printf("%6s", "-");
                else
                    System.out.printf("%6d", m[i][j]);
            }
            System.out.println();
        }

        System.out.println("\nMinimum number of multiplications = " + m[1][n]);
    }

    public static void main(String[] args) {
        MatrixChainMultiplication mc = new MatrixChainMultiplication();
        mc.getData();
        mc.matrixChainOrder();
    }
}
