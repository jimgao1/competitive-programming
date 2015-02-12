import java.util.Scanner;

public class ccc12s5 {
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int sizeX = keyboard.nextInt();
		int sizeY = keyboard.nextInt();
		
		int[][] dp = new int[sizeX + 1][sizeY + 1];
		boolean[][] hasCat = new boolean[sizeX + 1][sizeY + 1];
		
		int catCount = keyboard.nextInt();
		
		while(catCount-- != 0){
			int catX = keyboard.nextInt();
			int catY = keyboard.nextInt();
			
			hasCat[catX][catY] = true;
			dp[catX][catY] = 0;
		}
		
		dp[1][1] = 1;
		hasCat[1][1] = true;
		
		for (int i=1; i<sizeX + 1; i++)
			for (int j=1; j<sizeY + 1; j++)
				if (hasCat[i][j])
					continue;
				else
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
					
		System.out.println(dp[sizeX][sizeY]);
	}
}
