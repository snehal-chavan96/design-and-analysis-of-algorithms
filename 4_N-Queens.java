import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class NQueens {
    private int[][] board = new int[20][20];
    private int n;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter value of N: ");
        n = sc.nextInt();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = 0;
    }

    public boolean isSafe(int row, int col) {
        for (int i = 0; i < col; i++)
            if (board[row][i] == 1) return false;

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1) return false;

        for (int i = row, j = col; i < n && j >= 0; i++, j--)
            if (board[i][j] == 1) return false;

        return true;
    }

    public boolean solveNQ(int col) {
        if (col >= n) return true;

        ArrayList<Integer> rows = new ArrayList<>();
        for (int i = 0; i < n; i++)
            rows.add(i);

        Collections.shuffle(rows, new Random());

        for (int i = 0; i < n; i++) {
            int r = rows.get(i);

            if (isSafe(r, col)) {
                board[r][col] = 1;

                if (solveNQ(col + 1))
                    return true;

                board[r][col] = 0;
            }
        }

        return false;
    }

    public void display() {
        if (!solveNQ(0)) {
            System.out.println("Solution does not exist.");
            return;
        }

        System.out.println("\nSolution Matrix:");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                System.out.print(board[i][j] + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        NQueens q = new NQueens();
        q.getData();
        q.display();
    }
}
