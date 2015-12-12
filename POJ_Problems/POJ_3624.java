/*
        poj judge is fucking shit
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            try {
                br = new BufferedReader(new InputStreamReader(System.in));
            } catch (Exception ex){}
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) {
        FastScanner keyboard = new FastScanner();

        int N = keyboard.nextInt();
        int W = keyboard.nextInt();

        int[] weight = new int[3500];
        int[] value = new int[3500];

        for (int i = 1; i <= N; i++){
            weight[i] = keyboard.nextInt();
            value[i] = keyboard.nextInt();
        }

        int[][] dp = new int[2][13000];

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
