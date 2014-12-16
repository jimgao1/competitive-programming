import java.util.Scanner;

public class POJ_3176{
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        int gridSize = keyboard.nextInt();

        int[][] grid = new int[gridSize][gridSize];
        int[][] dp = new int[gridSize][gridSize];

        for (int i=0; i<gridSize; i++){
            for (int j=0; j<i + 1; j++){
                grid[j][i] = keyboard.nextInt();
                dp[j][i] = 0;
            }
        }

        for (int i=gridSize - 1; i >= 0; i -= 1){
            for (int j=0; j<i + 1; j++){
                if (i == gridSize - 1){
                    dp[j][i] = grid[j][i];
                } else {
                    dp[j][i] = Math.max(dp[j][i + 1], dp[j + 1][i + 1]) + grid[j][i];
                }
            }
        }

        System.out.println(dp[0][0]);
    }
}
