import java.util.Scanner;

public class FloydWarshall {
    private int[][] graph = new int[20][20];
    private int[][] dist = new int[20][20];
    private int n;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter number of vertices: ");
        n = sc.nextInt();

        System.out.println("\nEnter adjacency matrix:");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = sc.nextInt();
                dist[i][j] = graph[i][j];
            }
        }
    }

    public void floydWarshall() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Update shortest distance
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        display();
    }

    public void display() {
        System.out.println("\nShortest Path Matrix:");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%5d", dist[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        FloydWarshall f = new FloydWarshall();
        f.getData();
        f.floydWarshall();
    }
}
