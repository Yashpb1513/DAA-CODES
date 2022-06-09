import java.util.Scanner;

public class coindp {
    static int min(int i, int k) {
        return (i < k) ? i : k;
    }

    public static int coin(int deno[], int n, int total, int arr[]) {
        int table[][] = new int[n + 1][total + 1];
        // initialization
        for (int i = 0; i < total + 1; i++) {
            table[0][i] = Integer.MAX_VALUE - 1;
            arr[i] = -1;
        }
        for (int i = 1; i < n + 1; i++) {
            table[i][0] = 0;
        }
        // initializing first row
        for (int i = 1, j = 0; j < total + 1; j++) {
            if (j % deno[i] == 0) {
                table[i][j] = j / deno[i];
            } else {
                table[i][j] = Integer.MAX_VALUE - 1;
            }
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < total + 1; j++) {
                if (deno[i] <= j) {
                    table[i][j] = min(1 + table[i][j - deno[i]], table[i - 1][j - 1]);
                    arr[j] = i;
                } else {
                    table[i][j] = table[i - 1][j];
                }
            }
        }
        if (arr[arr.length - 1] == -1) {
            System.out.print("No solution is possible");
        } else {
            int start = arr.length - 1;
            System.out.print("Coins used to form total ");
            while (start != 0) {
                int j = arr[start];
                System.out.print(deno[j] + " ");
                start = start - deno[j];
            }
        }
        return table[n][total];
    }

    public static void main(String[] args) {
        System.out.println("Enter number of coins: ");
        try (Scanner sc = new Scanner(System.in)) {
            int n, total;
            n = sc.nextInt();
            System.out.println("Enter the total amount: ");
            total = sc.nextInt();
            int arr[] = new int[total + 1];
            int denomination[] = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                denomination[i] = sc.nextInt();
            }
            System.out.println(coin(denomination, n, total, arr));

        }
    }
}
