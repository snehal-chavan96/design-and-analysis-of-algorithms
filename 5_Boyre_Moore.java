import java.util.Scanner;

public class BoyerMoore {
    private String text;
    private String pattern;
    private int[] badChar = new int[256];
    private int[] goodSuffix = new int[105];
    private int[] bpos = new int[105];
    private Scanner sc = new Scanner(System.in);

    public void getData() {
        System.out.print("Enter text: ");
        text = sc.nextLine();

        System.out.print("Enter pattern: ");
        pattern = sc.nextLine();
    }

    public void badCharacterHeuristic(int m) {
        // Initialize all occurrences as -1
        for (int i = 0; i < 256; i++) {
            badChar[i] = -1;
        }

        // Store last occurrence of each character
        for (int i = 0; i < m; i++) {
            badChar[(int) pattern.charAt(i)] = i;
        }
    }

    public void preprocessStrongSuffix(int m) {
        int i = m;
        int j = m + 1;
        bpos[i] = j;

        // Initialize goodSuffix array
        for (int k = 0; k <= m; k++) {
            goodSuffix[k] = 0;
        }

        while (i > 0) {
            // Search for border
            while (j <= m && pattern.charAt(i - 1) != pattern.charAt(j - 1)) {
                if (goodSuffix[j] == 0) {
                    goodSuffix[j] = j - i;
                }
                j = bpos[j];
            }

            i--;
            j--;
            bpos[i] = j;
        }
    }

    public void preprocessCase2(int m) {
        int j = bpos[0];

        for (int i = 0; i <= m; i++) {
            if (goodSuffix[i] == 0) {
                goodSuffix[i] = j;
            }

            if (i == j) {
                j = bpos[j];
            }
        }
    }

    public void searchPattern() {
        int n = text.length();
        int m = pattern.length();

        // Edge case
        if (m == 0) {
            System.out.println("Empty pattern.");
            return;
        }

        // Build tables
        badCharacterHeuristic(m);
        preprocessStrongSuffix(m);
        preprocessCase2(m);

        int shift = 0;
        boolean found = false;

        while (shift <= (n - m)) {
            int j = m - 1;

            // Compare from right to left
            while (j >= 0 && pattern.charAt(j) == text.charAt(shift + j)) {
                j--;
            }

            // Pattern found
            if (j < 0) {
                System.out.println("\nPattern found at index " + shift);
                found = true;

                // Shift pattern safely
                shift += (goodSuffix[0] > 0) ? goodSuffix[0] : 1;
            } else {
                // Bad Character Shift
                int badCharShift = j - badChar[(int) text.charAt(shift + j)];
                badCharShift = Math.max(1, badCharShift);

                // Good Suffix Shift
                int goodSuffixShift = goodSuffix[j + 1];

                // Take maximum
                shift += Math.max(badCharShift, goodSuffixShift);
            }
        }

        if (!found) {
            System.out.println("\nPattern not found.");
        }

        // Display Bad Character Table
        System.out.println("\n\nBad Character Table:");

        for (int i = 0; i < m; i++) {
            System.out.println(pattern.charAt(i) + " -> " + badChar[(int) pattern.charAt(i)]);
        }

        // Display Good Suffix Table
        System.out.println("\nGood Suffix Table:");
        System.out.println("Full match shift -> " + goodSuffix[0]);
    }

    public static void main(String[] args) {
        BoyerMoore bm = new BoyerMoore();
        bm.getData();
        bm.searchPattern();
    }
}
