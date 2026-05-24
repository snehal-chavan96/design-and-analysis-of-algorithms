import java.util.Scanner;

public class NaivePattern {
    private String text;
    private String pattern;
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter text: ");
        text = sc.nextLine();

        System.out.print("Enter pattern: ");
        pattern = sc.nextLine();
    }

    public void searchPattern() {
        int n = text.length();
        int m = pattern.length();

        boolean found = false;

        // Slide pattern over text
        for (int i = 0; i <= n - m; i++) {
            int j;

            // Compare pattern characters
            for (j = 0; j < m; j++) {
                if (text.charAt(i + j) != pattern.charAt(j)) {
                    break;
                }
            }

            // Pattern found
            if (j == m) {
                System.out.println("\nPattern found at position " + (i + 1));
                found = true;
            }
        }

        if (!found) {
            System.out.println("\nPattern not found.");
        }
    }

    public static void main(String[] args) {
        NaivePattern n = new NaivePattern();
        n.getData();
        n.searchPattern();
    }
}
