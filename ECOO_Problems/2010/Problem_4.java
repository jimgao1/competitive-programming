import java.io.File;
import java.util.Scanner;

public class Problem_4 {
	
	public static int romanToInt(String r){
		if (r.length() == 0) return 0;
		
		if (r.startsWith("M")) return 1000 + romanToInt(r.substring(1));
		if (r.startsWith("CM")) return 900 + romanToInt(r.substring(2));
		if (r.startsWith("D")) return 500 + romanToInt(r.substring(1));
		if (r.startsWith("CD")) return 400 + romanToInt(r.substring(2));
		if (r.startsWith("C")) return 100 + romanToInt(r.substring(1));
		if (r.startsWith("XC")) return 90 + romanToInt(r.substring(2));
		if (r.startsWith("L")) return 50 + romanToInt(r.substring(1));
		if (r.startsWith("XL")) return 40 + romanToInt(r.substring(2));
		if (r.startsWith("X")) return 10 + romanToInt(r.substring(1));
		if (r.startsWith("IX")) return 9 + romanToInt(r.substring(2));
		if (r.startsWith("V")) return 5 + romanToInt(r.substring(1));
		if (r.startsWith("IV")) return 4 + romanToInt(r.substring(2));
		if (r.startsWith("I")) return 1 + romanToInt(r.substring(1));
		
		return 0;
	}
	
	public static String IntegerToRomanNumeral(int input) {
	    if (input < 1 || input > 3999)
	        return "Invalid Roman Number Value";
	    String s = "";
	    while (input >= 1000) {
	        s += "M";
	        input -= 1000;        }
	    while (input >= 900) {
	        s += "CM";
	        input -= 900;
	    }
	    while (input >= 500) {
	        s += "D";
	        input -= 500;
	    }
	    while (input >= 400) {
	        s += "CD";
	        input -= 400;
	    }
	    while (input >= 100) {
	        s += "C";
	        input -= 100;
	    }
	    while (input >= 90) {
	        s += "XC";
	        input -= 90;
	    }
	    while (input >= 50) {
	        s += "L";
	        input -= 50;
	    }
	    while (input >= 40) {
	        s += "XL";
	        input -= 40;
	    }
	    while (input >= 10) {
	        s += "X";
	        input -= 10;
	    }
	    while (input >= 9) {
	        s += "IX";
	        input -= 9;
	    }
	    while (input >= 5) {
	        s += "V";
	        input -= 5;
	    }
	    while (input >= 4) {
	        s += "IV";
	        input -= 4;
	    }
	    while (input >= 1) {
	        s += "I";
	        input -= 1;
	    }    
	    return s;
	}
	
	
	public static void main(String[] args) throws Exception{
		Scanner keyboard = new Scanner(System.in);
		
		for (int c = 0; c < 5; c++){
			String r1 = keyboard.nextLine();
			String r2 = keyboard.nextLine();
			
			System.out.print(r1 + " + " + r2 + " = ");
			System.out.println(IntegerToRomanNumeral(romanToInt(r1) + romanToInt(r2)));
			
		}
		
	}
}
