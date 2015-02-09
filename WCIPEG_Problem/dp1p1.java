
import java.util.Scanner;

public class dp1p1 {
	
	public static int[] numbers;
	public static int[] dp;

	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int numberCount = keyboard.nextInt();
		
		numbers = new int[numberCount];
		dp = new int[numberCount];
		
		for (int i=0; i<numberCount; i++)
			numbers[i] = keyboard.nextInt();
		
		dp[0] = numbers[0];
		dp[1] = numbers[1];
		
		for (int i=2; i<numberCount; i++){
			int maxDP = -1;
			
			for (int j=i - 2; j>=i-4 && j >= 0; j--)
				maxDP = Math.max(maxDP, dp[j] + numbers[i]);
			
			dp[i] = Math.max(numbers[i], maxDP);
		}
	
		int maxSum = Integer.MIN_VALUE;
		
		for (int i=0; i<numberCount; i++)
			maxSum = Math.max(maxSum, dp[i]);
		
		System.out.println(maxSum);
	}
	

}
