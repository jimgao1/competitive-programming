import java.util.Scanner;

public class EditDistance {

	/*
	 * 		Function definition:
	 * 			f(x, y) = edit distance between x and y
	 * 						     --OR--
	 * 			f(i, j) = edit distance between x[0...i] and y[0...j];
	 * 
	 * 
	 * 			f(0, 0) = 0;				 (an empty string to another one)
	 * 			f(k, 0) = k;  f(0, k) = k;   (only need k delete operation) 
	 * 
	 * 			Transformation Formula: https://web.stanford.edu/class/cs124/lec/med.pdf
	 */
	
	public static int min(int[] numbers){
		int min = Integer.MAX_VALUE;
		
		for (int i=0; i<numbers.length; i++)
			if (numbers[i] < min) min = numbers[i];
		
		return min;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		String s1 = keyboard.next();
		String s2 = keyboard.next();
		
		int[][] dp = new int[s1.length()][s2.length()];
		
		for (int i=0; i<s1.length(); i++){
			for (int j=0; j<s2.length(); j++){
				if (i == 0 || j == 0){
					if (i == 0 && j == 0) dp[i][j] = 0;
					if (i == 0) dp[i][j] = j + 1;
					if (j == 0) dp[i][j] = i + 1;
				} else {
					int[] opt = new int[3];
					
					opt[0] = dp[i - 1][j] + 1;
					opt[1] = dp[i][j - 1] + 1;
					
					if (s1.charAt(i) == s2.charAt(j)){
						opt[2] = 0;
					} else {
						opt[2] = 2;
					}
					
					opt[2] += dp[i - 1][j - 1];
					
					dp[i][j] = min(opt);
				}
			}
		}
		
		System.out.println(dp[s1.length() - 1][s2.length() - 1] - 1);
	}
	
}
