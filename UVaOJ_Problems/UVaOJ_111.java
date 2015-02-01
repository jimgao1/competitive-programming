import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class UVaOJ_111 {

	public static int[] correctResponse;
	public static int[] correctResponseID;
	public static int responseLength;
	
	public static Map<Integer, Integer> dictionary;
	
	public static int lis(int[] numbers){
		int[] dp = new int[numbers.length];
		
		for (int i=0; i<numbers.length; i++) dp[i] = 1;
		
		for (int i=0; i<numbers.length; i++){
			int maxSubLength = Integer.MIN_VALUE;
			
			for (int j=0; j<i; j++)
				if (dp[j] > maxSubLength && numbers[j] < numbers[i])
					maxSubLength = dp[j];
			
			dp[i] = Math.max(dp[i], maxSubLength + 1);
		}
		
		int maxLength = Integer.MIN_VALUE;
		
		for (int i=0; i<dp.length; i++)
			if (dp[i] > maxLength) maxLength = dp[i];
		
		return maxLength;
	}
	
	public static int LongestCommonSubsequence(int[] arrayA, int[] arrayB){
		int[][] dp = new int[arrayA.length][arrayB.length];
		
		for (int i=0; i<arrayA.length; i++){
			for (int j=0; j<arrayB.length; j++){
				if (i == 0 || j == 0){
					dp[i][j] = 0;
				} else if (arrayA[i] == arrayB[j]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		
		return dp[arrayA.length - 1][arrayB.length - 1] + 1;
	}
	
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		responseLength = keyboard.nextInt();
		
		correctResponse = new int[responseLength];
		correctResponseID = new int[responseLength];
		
		
		dictionary = new HashMap<Integer, Integer>();
		
		for (int i=0; i<responseLength; i++){
			correctResponse[i] = keyboard.nextInt();
			correctResponseID[i] = i;
			dictionary.put(correctResponse[i], i);
		}
		
		while(keyboard.hasNext()){
			int[] response = new int[responseLength];
			
			for (int i=0; i<responseLength; i++)
				response[i] = dictionary.get(keyboard.nextInt());
			
			System.out.println(LongestCommonSubsequence(response, correctResponseID));
		}
	}

}
