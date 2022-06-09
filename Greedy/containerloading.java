import java.util.*;

public class containerloading implements Comparable<containerloading> {
    private int weights, id, flag;
    static int f = 1;

    public containerloading(int weights, int id) {
        this.weights = weights;
        this.id = id;
    }

    public static int loading(containerloading arr[], int n, int capacity) {
        int solution = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].weights + solution < capacity) {
                solution += arr[i].weights;
                arr[i].flag = 1;
            }
        }
        return solution;
    }

    public static void main(String[] args) {
        System.out.println("Enter number of container: ");
        try (Scanner sc = new Scanner(System.in)) {
            int n, w;
            n = sc.nextInt();
            System.out.println("Enter the capacity: ");
            w = sc.nextInt();
            containerloading weights[] = new containerloading[n];
            for (int i = 0; i < n; i++) {
                weights[i] = new containerloading(sc.nextInt(), i + 1);
            }
            Arrays.sort(weights);
            System.out.println("Total cost: " + loading(weights, n, w));
            f = 0;
            Arrays.sort(weights);
            for (containerloading temp : weights) {
                System.out.println("Contianer: " + temp.id + " Flag: " + temp.flag);
            }
        }
    }

    @Override
    public int compareTo(containerloading o) {
        if (f == 1) {
            return this.weights - o.weights;
        } else {
            return this.id - o.id;
        }
    }
};