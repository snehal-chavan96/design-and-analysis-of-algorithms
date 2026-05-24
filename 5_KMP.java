import java.util.Scanner;

public class KMP {
    private String text;
    private String pattern;
    private int[] lps = new int[100];
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter text: ");
        text = sc.nextLine();

        System.out.print("Enter pattern: ");
        pattern = sc.nextLine();
    }

    public void computeLPS() {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        int m = pattern.length();

        while (i < m) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    public void KMPSearch() {
        computeLPS();

        int n = text.length();
        int m = pattern.length();

        int i = 0;
        int j = 0;

        boolean found = false;

        // Start timing
        long start = System.nanoTime();

        while (i < n) {
            if (pattern.charAt(j) == text.charAt(i)) {
                i++;
                j++;
            }

            // Pattern found
            if (j == m) {
                System.out.println("\nPattern found at index " + (i - j));
                found = true;
                j = lps[j - 1];
            } else if (i < n && pattern.charAt(j) != text.charAt(i)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        // End timing
        long end = System.nanoTime();
        double timeTaken = (end - start) / 1_000_000_000.0;

        if (!found) {
            System.out.println("\nPattern not found.");
        }

        // Display LPS Table
        System.out.println("\n\nLPS Table:");

        for (int k = 0; k < m; k++) {
            System.out.print(pattern.charAt(k) + " ");
        }

        System.out.println();

        for (int k = 0; k < m; k++) {
            System.out.print(lps[k] + " ");
        }

        System.out.println("\n\nTime Required = " + timeTaken + " seconds");
    }

    public static void main(String[] args) {
        KMP k = new KMP();
        k.getData();
        k.KMPSearch();
    }
}
