import java.util.Scanner;

public class binomialcoefficients {
    static int min(int i, int k) {
        return (i > k) ? k : i;
    }

    static int coeff(int coefficient[][], int n, int k) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= min(i, k); j++) {
                if (i == j || j == 0) {
                    coefficient[i][j] = 1;
                } else {
                    coefficient[i][j] = coefficient[i - 1][j - 1] + coefficient[i - 1][j];
                }
            }
        }
        return coefficient[n][k];
    }

    public static void main(String[] args) {
        System.out.println("Enter value of n and k: ");
        try (Scanner sc = new Scanner(System.in)) {
            int n, k;
            n = sc.nextInt();
            k = sc.nextInt();
            int coefficient[][] = new int[n + 1][k + 1];
            System.out.println("value: " + coeff(coefficient, n, k));
        }
    }
}