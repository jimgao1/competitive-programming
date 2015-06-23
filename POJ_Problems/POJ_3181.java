import java.math.*;
import java.util.*;

public class POJ_3181{

	public static BigInteger[] dp;

	public static void main(String[] args){
		dp = new BigInteger[1001];
		
		Scanner keyboard = new Scanner(System.in);
		
		int N, K;
		N = keyboard.nextInt();
		K = keyboard.nextInt();
		
		dp[0] = new BigInteger("1");

		for (int i=1; i<1001; i++) dp[i] = new BigInteger("0");
		
		for (int i=1; i<=K; i++){
			for (int j=i; j<=N; j++)
				dp[j] = dp[j].add(dp[j - i]);
		}
		
		System.out.println(dp[N].toString());
	}
}
