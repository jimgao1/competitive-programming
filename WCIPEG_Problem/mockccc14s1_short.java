import java.util.Scanner;

public class mockccc14s1 {
	
	/*
	 * 	The fucked up version of the code
	 * 		(only 23 lines)
	 * 
	 * 	by Jim Gao
	 */
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		String source = keyboard.nextLine();
		
		int firstIndex = new StringBuilder(source).reverse().toString().indexOf(keyboard.nextLine());
		
		if (firstIndex == -1)
			System.out.println(-1);
		else
			System.out.println(source.length() - firstIndex);
		
	}
}
