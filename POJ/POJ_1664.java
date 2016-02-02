import java.util.Scanner;

public class POJ_1664 {
	
	public static int appleCount;
	public static int plateCount;
	
	public static int count(int apple, int plate){
		if (apple == 1 || plate == 1) return 1;
		if (apple < plate) return count(apple, plate - 1);
		
		return count(apple - plate, plate) + count(apple, plate - 1);
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int caseCount = keyboard.nextInt();
		
		for (int i=0; i<caseCount; i++){
			appleCount = keyboard.nextInt();
			plateCount = keyboard.nextInt();
			
			System.out.println(count(appleCount, plateCount));
		}
	}
}
