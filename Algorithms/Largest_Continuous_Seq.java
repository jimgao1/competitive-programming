import java.util.Scanner;

public class Largest_Continuous_Seq {
	
	/*
	 * 		Problem Description:
	 * 
	 * 			I have a list of numbers, and I am trying to
	 * 			find a continuous sequence that has the 
	 * 			greatest sum. 
	 */
	
	public static int max(int a, int b){
		if (a > b) return a;
		return b;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int numberCount = keyboard.nextInt();
		int[] numbers = new int[numberCount];
		int max = Integer.MIN_VALUE;
		
		for (int i=0; i<numberCount; i++) numbers[i] = keyboard.nextInt();
		
		int[] f = new int[numberCount];
		
		f[0] = numbers[0];
		for (int i=1; i<numberCount; i++){
			f[i] = max(f[i - 1] + numbers[i], numbers[i]);
			if (f[i] > max) max = f[i];
		}
		
		System.out.println(max);
	}
}
