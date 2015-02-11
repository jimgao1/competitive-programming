import java.util.Scanner;

public class ccc08s5 {
	
	/*
	 * 		This code works for BOTH ccc08j5 and ccc08s5 
	 */
	
	public static boolean combo1(int[] combo){
		return combo[0] >= 2 && combo[1] >= 1 && combo[3] >= 2;
	}
	
	public static boolean combo2(int[] combo){
		return combo[0] >= 1 && combo[1] >= 1 && combo[2] >= 1 && combo[3] >= 1;
	}
	
	public static boolean combo3(int[] combo){
		return combo[2] >= 2 && combo[3] >= 1;
	}
	
	public static boolean combo4(int[] combo){
		return combo[1] >= 3;
	}
	
	public static boolean combo5(int[] combo){
		return combo[0] >= 1 && combo[3] >= 1;
	}
	
	public static boolean canMove(int[] combo){
		return combo1(combo) || combo2(combo) || combo3(combo) || combo4(combo) || combo5(combo);
	}
	
	public static boolean containsNegative(int[] combo){
		if (combo[0] < 0 || combo[1] < 0 || combo[2] < 0 || combo[3] < 0) return true;
		return false;
	}
	
	public static byte[][][][] dp;
	
	public static boolean winningCombo(int[] combo){
		if (!canMove(combo)) return false;
		
		if (containsNegative(combo)) return false;
		
		if (dp[combo[0]][combo[1]][combo[2]][combo[3]] != -1)
			return dp[combo[0]][combo[1]][combo[2]][combo[3]] == 1;
		
		if (combo1(combo)){
			int[] newCombo = {
				combo[0] - 2, combo[1] - 1, combo[2], combo[3] - 2	
			};
			
			if (!winningCombo(newCombo))
				dp[combo[0]][combo[1]][combo[2]][combo[3]] = 1;
		}
		
		if (combo2(combo)){
			int[] newCombo = {
				combo[0] - 1, combo[1] - 1, combo[2] - 1, combo[3] - 1
			};
			
			if (!winningCombo(newCombo))
				dp[combo[0]][combo[1]][combo[2]][combo[3]] = 1;
		}
		
		if (combo3(combo)){
			int[] newCombo = {
				combo[0], combo[1], combo[2] - 2, combo[3] - 1
			};
			
			if (!winningCombo(newCombo))
				dp[combo[0]][combo[1]][combo[2]][combo[3]] = 1;
		}
		
		if (combo4(combo)){
			int[] newCombo = {
				combo[0], combo[1] - 3, combo[2], combo[3]
			};
			
			if (!winningCombo(newCombo))
				dp[combo[0]][combo[1]][combo[2]][combo[3]] = 1;
		}
		
		if (combo5(combo)){
			int[] newCombo = {
				combo[0] - 1, combo[1], combo[2], combo[3] - 1
			};
			
			if (!winningCombo(newCombo))
				dp[combo[0]][combo[1]][combo[2]][combo[3]] = 1;
		}
		
		if (dp[combo[0]][combo[1]][combo[2]][combo[3]] == 1)
			return true;
		else
			return false;
		
	}
	
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		dp = new byte[31][31][31][31];
		
		for (int i=0; i<31; i++)
			for (int j=0; j<31; j++)
				for (int k=0; k<31; k++)
					for (int l=0; l<31; l++)
						dp[i][j][k][l] = -1;
		
		int caseCount = keyboard.nextInt();
		
		while(caseCount-- != 0){
		
			int[] initial = {
				keyboard.nextInt(),
				keyboard.nextInt(),
				keyboard.nextInt(),
				keyboard.nextInt()
			};
			
			if (!winningCombo(initial))
				System.out.println("Roland");
			else 
				System.out.println("Patrick");
		
		}
	}
}
