import java.io.File;
import java.util.Scanner;

public class Problem_3{
	
	public static int gcd(int a, int b){
		for (int i=Math.min(a, b); i>=1; i--)
			if (a % i == 0 && b % i == 0) return i;
		return 1;
	}
	
	public static void main(String[] args) throws Exception{
		Scanner keyboard = new Scanner(new File("input3.txt"));
		
		for (int c = 0; c < 5; c++){
			int a = keyboard.nextInt();
			int b = keyboard.nextInt();
			
			int tA = a;
			int tB = b;
			
			if (a > b){
				int temp = a;
				a = b;
				b = temp;
			}
			
			long tileCount = Integer.MAX_VALUE;
			int tileType = -1;
			long tileX = -1;
			long tileY = -1;
			
			/*
			 * 		1 = n * n
			 * 		2 = 2n * n
			 * 		3 = 3n * 2n
			 */
			
			for (int i=1; i <= a && i <= b; i++){
				if (a % i == 0 && b % i == 0){
					long t = ((long)b / i) * (a / i);
					if (t < 0) continue;
					
					if (t < tileCount){
						tileCount = t;
						tileType = 1;
						tileX = i;
						tileY = i;
					}
				}
			}
			
			for (int i=1; i <= a && i * 2 <= b; i++){
				if (a % i == 0 && b % (2 * i) == 0){
					long t = (a / i) * (b / (2 * i));
					if (t < 0) continue;
					
					if (t < tileCount){
						tileCount = t;
						tileType = 2;
						tileX = 2 * i;
						tileY = i;
					}
				}
			}
			
			for (int i=1; (2 * i <= a && 3 * i <= b) || (3 * i <= a && 2 * i <= b); i++){
				if (a % (2 * i) == 0 && b % (3 * i) == 0){
					long t = ((long)a / (2 * (long)i)) * ((long)b / (3 * i));
					if (t < 0) continue;
					
					if (t < tileCount){
						tileCount = t;
						tileType = 3;
						tileX = 3 * i;
						tileY = 2 * i;
					}
				}
			}
			
			System.out.printf("For a (%d x %d) floor: Use %d (%d by %d) tiles \n",
					tA, tB, tileCount, tileX, tileY);
			
		}
	}
	
}
