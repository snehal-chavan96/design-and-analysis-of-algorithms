import java.util.Scanner;

public class RabinKarp {
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

        int patternHash = 0;
        int textHash = 0;

        // Calculate pattern hash
        System.out.println("\nPattern Character Hash Values:");

        for (int i = 0; i < m; i++) {
            System.out.println(pattern.charAt(i) + " = " + (int) pattern.charAt(i));
            patternHash += pattern.charAt(i);
        }

        System.out.println("\nPattern Total Hash = " + patternHash);

        // First window hash
        for (int i = 0; i < m; i++) {
            textHash += text.charAt(i);
        }

        System.out.println("\nIndex\tWindow\tHash");
        System.out.println("-----------------------------");

        // Sliding window
        for (int i = 0; i <= n - m; i++) {
            // Print current window
            System.out.print(i + "\t");

            for (int j = 0; j < m; j++) {
                System.out.print(text.charAt(i + j));
            }

            System.out.println("\t" + textHash);

            // If hash matches
            if (patternHash == textHash) {
                int j;

                // Character comparison
                for (j = 0; j < m; j++) {
                    if (text.charAt(i + j) != pattern.charAt(j)) {
                        break;
                    }
                }

                if (j == m) {
                    System.out.println("Pattern found at index " + i);
                }
            }

            // Next window hash
            if (i < n - m) {
                textHash = textHash - text.charAt(i) + text.charAt(i + m);
            }
        }
    }

    public static void main(String[] args) {
        RabinKarp r = new RabinKarp();
        r.getData();
        r.searchPattern();
    }
}
