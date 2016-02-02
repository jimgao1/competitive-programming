import java.util.Scanner;


public class POJ_2453 {
	
	public static int countOne(int input){
	     int count=0;
	     for (int i=0;i<21;i++)
	     {
	         if (((input >> i & 1) == 1))
	           count += 1;
	     }
	     return count;
	    
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		while(true){
			int n = keyboard.nextInt();
			int count = countOne(n);
			
			if (n == 0) break;
			
			int temp = n + 1;
			while(true){
				if (countOne(temp) == count){
					System.out.println(temp);
					break;
				}
				temp += 1;
			}
			
			if (n == 0) break;
		}
	}
}
