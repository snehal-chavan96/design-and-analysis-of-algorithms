import java.util.Scanner;

public class LargeIntegerMultiplication {
    private Scanner sc = new Scanner(System.in);

    public int digits(long n) {
        int count = 0;
        while (n > 0) {
            count++;
            n = n / 10;
        }
        return count;
    }

    public long multiply(long x, long y) {
        if (x < 10 || y < 10) {
            return x * y;
        }

        int n = Math.max(digits(x), digits(y));
        int half = n / 2;

        long power = (long) Math.pow(10, half);

        long a = x / power;
        long b = x % power;

        long c = y / power;
        long d = y % power;

        long ac = multiply(a, c);
        long bd = multiply(b, d);
        long adbc = multiply(a + b, c + d) - ac - bd;

        return (long) (ac * Math.pow(10, 2 * half)) + (adbc * power) + bd;
    }

    public static void main(String[] args) {
        LargeIntegerMultiplication obj = new LargeIntegerMultiplication();
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first large number: ");
        long num1 = sc.nextLong();

        System.out.print("Enter second large number: ");
        long num2 = sc.nextLong();

        long result = obj.multiply(num1, num2);

        System.out.println("\nMultiplication result = " + result);

        sc.close();
    }
}
