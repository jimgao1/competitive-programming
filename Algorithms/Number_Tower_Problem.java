import java.util.Scanner;

public class Number_Tower_Problem {
	
	/*
	 * 		I have a tower of numbers, like this:
	 * 			1
	 * 			2  3
	 * 			4  5  6
	 * 			7  8  9  10
	 * 
	 * 		I start from the top one, and go down one
	 * 		at a time. I want to know the largest sum
	 * 		I can get from it. 
	 */
	
	public static int max(int a, int b){
		if (b > a) return b;
		return a;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int size = keyboard.nextInt();
		int[][] tower = new int[size][size];
		int[][] f = new int[size][size];
		
		for (int i=0; i<size; i++){
			for (int j=0; j < i + 1; j++){
				tower[j][i] = keyboard.nextInt();
			}
		}
		
		for (int i=size - 1; i >= 0; i -= 1){
			for (int j=0; j < i + 1; j++){
				if (i == size - 1){
					f[j][i] = tower[j][i];
				} else {
					f[j][i] = max(f[j][i + 1], f[j + 1][i + 1]) + tower[j][i];
				}
			}
		}
		
		System.out.println(f[0][0]);
	}
}
