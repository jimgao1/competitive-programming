import java.util.Scanner;

public class dp1p3 {
	
	public static int countLIS(int[] numbers){
		int numberCount = numbers.length;
		int[] dp = new int[numberCount];
		
		/*
		 * 		Function Definition:
		 * 			dp[i] = Length of the longest LIS up to index i
		 * 
		 *  	Transitional Formula:
		 *  		dp[i] = max(dp[0] .. dp[i - 1]) + 1
		 *  
		 *  	Computational Complexity:
		 *  		O(n^2)
		 */
		
		for (int i=0; i<numberCount; i++)
			dp[i] = 1;
		
		for (int i=0; i<numberCount; i++){
			int maxLength = -1;
			
			for (int j=0; j<i; j++)
				if (numbers[j] < numbers[i])
					maxLength = Math.max(maxLength, dp[j] + 1);
			
			dp[i] = Math.max(dp[i], maxLength);
		}
		
		int maxLength = -1;
		
		for (int n : dp)
			maxLength = Math.max(maxLength, n);
		
		return maxLength;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int numberCount = keyboard.nextInt();
		int[] numbers = new int[numberCount];
		
		for (int i=0; i<numberCount; i++)
			numbers[i] = keyboard.nextInt();
		
		System.out.println(countLIS(numbers));
	}
}
