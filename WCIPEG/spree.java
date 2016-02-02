
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class spree {

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        int N = keyboard.nextInt();
        int W = keyboard.nextInt();

        int[] weight = new int[N + 1];
        int[] value = new int[N + 1];

        for (int i = 1; i <= N; i++){
            value[i] = keyboard.nextInt();
            weight[i] = keyboard.nextInt();
        }

        int[][] dp = new int[2][W + 1];

        for (int i = 1; i <= N; i++){
            for (int j = 0; j <= W; j++){
                if (weight[i] <= j)
                    dp[i % 2][j] = Math.max(dp[(i - 1) % 2][j],
                            dp[(i - 1) % 2][j - weight[i]] + value[i]);
                else
                    dp[i % 2][j] = dp[(i - 1) % 2][j];
            }
        }

        int ans = 0;

        System.out.printf("%d\n", Math.max(dp[0][W], dp[1][W]));

    }
}
