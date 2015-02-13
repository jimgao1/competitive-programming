import java.util.Scanner;

public class primes1 {
	public static boolean prime(int n){
		for (int i=2; i<(int)(Math.sqrt(n) + 1); i++)
			if (n % i == 0) return false;
		
		return true;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int n = keyboard.nextInt();
		
		int counter = 2;
		while(n > 0){
			if (prime(counter)){
				System.out.println(counter);
				n -= 1;
			}
			
			counter += 1;
		}
		
		
	}
}
