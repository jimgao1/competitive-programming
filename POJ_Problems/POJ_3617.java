import java.util.Scanner;

public class POJ_3617{
	
	/*
	 * 		PROGRAM WORKS BUT WHEN I SUBMIT IT IT SAIDS:
	 * 		PRESENTATION ERROR
	 * 
	 * 		DONT KNOW WHY
	 */
	
	public static int rating(String r1, String r2){
		while(!r1.equals("") && !r2.equals("")){
			char charA = r1.charAt(0);
			char charB = r2.charAt(0);
			
			r1 = r1.substring(1);
			r2 = r2.substring(1);
			
			if (charA != charB){
				if (charA > charB) return 2;
				return 1;
			}
		}
		
		if (r1.equals("") && r2.equals("")){
			return 0;
		} else {
			if (r1.equals("")) return 2;
			return 1;
		}
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int strLength = keyboard.nextInt();
		String str = "";
		
		for (int i=0; i<strLength; i++){
			str += keyboard.next();
		}
		
		while(!str.equals("")){
			if (str.length() == 1){
				System.out.print(str);
				break;
			}
			
			char letterA = str.charAt(0);
			char letterB = str.charAt(str.length() - 1);
			
			if (letterA != letterB){
				if (letterA > letterB){
					System.out.print(letterB);
					str = str.substring(0, str.length() - 1);
				} else {
					System.out.print(letterA);
					str = str.substring(1);
				}
			} else {
				String rev = new StringBuilder(str).reverse().toString();
				
				int r = rating(str, rev);
				if (r == 1){
					System.out.print(letterA);
					str = str.substring(1);
				} else {
					System.out.print(letterB);
					str = str.substring(0, str.length() - 1);
				}
			}
		}
	}
}
