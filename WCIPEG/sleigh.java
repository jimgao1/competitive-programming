import java.util.Scanner;

public class sleigh {
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int totalSum = 0;
		int maxRootLength = 0;
		
		int edgeCount = keyboard.nextInt();
		
		int[] dp = new int[edgeCount + 1];
		
		while(edgeCount-- != 0){
			int nA = keyboard.nextInt();
			int nB = keyboard.nextInt();
			int dist = keyboard.nextInt();
			
			dp[nB] = dp[nA] + dist;
			
			totalSum += 2 * dist;
			

			maxRootLength = Math.max(maxRootLength, dp[nB]);
		}
		
		System.out.println(totalSum - maxRootLength);
		
	}
}

