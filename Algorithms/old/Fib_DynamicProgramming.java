import java.util.Scanner;

public class Fib_DynamicProgramming {
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int n = keyboard.nextInt();
		
		int[] fib = new int[n];
		
		fib[0] = 1;
		fib[1] = 1;
		
		for (int i=2; i<n; i++){
			fib[i] = fib[i - 1] + fib[i - 2];
		}
		
		System.out.println(fib[n - 1]);
	}
}
