import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Knap01 {
    private int profit, weight, id;
    public static Set<Integer> vec = new HashSet<Integer>();

    public Knap01(int profit, int weight) {
        this.profit = profit;
        this.weight = weight;
    }

    public static int coin(Knap01 deno[], int n, int total, int arr[]) {
        int table[][] = new int[n + 1][total + 1];
        // initialization
        for (int i = 0, j = 0; i < n + 1 && j < total + 1; i++, j++) {
            table[0][j] = 0;
            table[i][0] = 0;
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < total + 1; j++) {
                if (deno[i - 1].weight <= j) {
                    table[i][j] = Math.max(deno[i - 1].profit + table[i - 1][j - deno[i - 1].weight], table[i - 1][j]);

                } else {
                    table[i][j] = table[i - 1][j];
                }
            }
        }
        int ans = table[n][total];
        for (int i = n, j = total; i > 0 && ans>0; i--) {
            if (table[i - 1][j] == ans) {
                continue;
            } else {
                vec.add(deno[i - 1].id);
                ans -= deno[i - 1].profit;
                j -= deno[i - 1].weight;
            }
        }
        return table[n][total];
    }

    public static void main(String[] args) {
        System.out.println("Enter number of items: ");
        try (Scanner sc = new Scanner(System.in)) {
            int n, total;
            n = sc.nextInt();
            System.out.println("Enter the total weight: ");
            total = sc.nextInt();
            Knap01 profit[] = new Knap01[n];
            int arr[] = new int[total + 1];
            for (int i = 0; i < n; i++) {
                profit[i] = new Knap01(sc.nextInt(), sc.nextInt());
                profit[i].id = i + 1;
            }
            System.out.println(coin(profit, n, total, arr));
            System.out.println(vec);
        }
    }
}
