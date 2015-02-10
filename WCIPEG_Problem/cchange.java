import java.util.Scanner;

public class cchange {
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int totalValue = keyboard.nextInt();
		int coinTypes = keyboard.nextInt();
		
		int[] dp = new int[totalValue + 1];
		int[] coinValues = new int[coinTypes];
		
		for (int i=0; i<coinTypes; i++)
			coinValues[i] = keyboard.nextInt();
		
		for (int i=0; i<coinTypes; i++)
			dp[i] = Integer.MAX_VALUE;
		
		

		dp[0] = 0;
		
		for (int i=1; i<totalValue + 1; i++){
			int minChange = 1000000;
			
			for (int j=0; j<coinTypes; j++){
				if (i - coinValues[j] >= 0)
					minChange = Math.min(minChange, dp[i - coinValues[j]] + 1);
			}
			
			dp[i] = minChange;
		}
		
		System.out.println(dp[totalValue]);
	}
}
