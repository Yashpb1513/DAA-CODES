import java.util.*;

class CoinChanging {
    static Vector<Integer> solution = new Vector<>();

    static void coin(int deno[], int coins, int n) {
        for (int i = n - 1; i >= 0; i--) {
            if (coins >= deno[i]) {
                solution.add(deno[i]);
                coins -= deno[i];
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("Enter number of coins in ascending order of denomination: ");
        try (Scanner sc = new Scanner(System.in)) {
            int n, total;
            n = sc.nextInt();
            System.out.println("Enter the total amount: ");
            total = sc.nextInt();
            int denomination[] = new int[n];
            for (int i = 0; i < n; i++) {
                denomination[i] = sc.nextInt();
            }
            coin(denomination, total,n);
            System.out.println(solution);
        }
    }
}