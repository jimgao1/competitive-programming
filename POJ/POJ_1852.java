import java.util.Scanner;

public class POJ_1852 {
	
	public static int max(int a, int b){
		if (b > a) return b;
		return a;
	}
	
	public static int min(int a, int b){
		if (b > a) return a;
		return b;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int caseCount = keyboard.nextInt();
		
		for (int i=0; i<caseCount; i++){
			int poleLength = keyboard.nextInt();
			int antCount = keyboard.nextInt();
			
			int[] ants = new int[antCount];
			
			for (int j=0; j<antCount; j++) ants[j] = keyboard.nextInt();
			
			int minTime = 0;
			int maxTime = 0;
			
			for (int j=0; j<antCount; j++){
				int distanceA = ants[j];
				int distanceB = poleLength - ants[j];
				
				minTime = max(minTime, min(distanceA, distanceB));
				maxTime = max(maxTime, max(distanceA, distanceB));
			}
			
			System.out.printf("%d %d\n", minTime, maxTime);
		}
	}
}
