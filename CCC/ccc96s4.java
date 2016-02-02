import java.util.Scanner;

public class ccc96s4 {
	public static int romanToDecimal(java.lang.String romanNumber) {
	    int decimal = 0;
	    int lastNumber = 0;
	    String romanNumeral = romanNumber.toUpperCase();
	         /* operation to be performed on upper cases even if user enters roman values in lower case chars */
	    for (int x = romanNumeral.length() - 1; x >= 0 ; x--) {
	        char convertToDecimal = romanNumeral.charAt(x);

	        switch (convertToDecimal) {
	            case 'M':
	                decimal = processDecimal(1000, lastNumber, decimal);
	                lastNumber = 1000;
	                break;

	            case 'D':
	                decimal = processDecimal(500, lastNumber, decimal);
	                lastNumber = 500;
	                break;

	            case 'C':
	                decimal = processDecimal(100, lastNumber, decimal);
	                lastNumber = 100;
	                break;

	            case 'L':
	                decimal = processDecimal(50, lastNumber, decimal);
	                lastNumber = 50;
	                break;

	            case 'X':
	                decimal = processDecimal(10, lastNumber, decimal);
	                lastNumber = 10;
	                break;

	            case 'V':
	                decimal = processDecimal(5, lastNumber, decimal);
	                lastNumber = 5;
	                break;

	            case 'I':
	                decimal = processDecimal(1, lastNumber, decimal);
	                lastNumber = 1;
	                break;
	        }
	    }
	    return decimal;
	}

	public static int processDecimal(int decimal, int lastNumber, int lastDecimal) {
	    if (lastNumber > decimal) {
	        return lastDecimal - decimal;
	    } else {
	        return lastDecimal + decimal;
	    }
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
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int caseCount = keyboard.nextInt();
		keyboard.nextLine();
		
		while(caseCount-- != 0){
			String input = keyboard.nextLine();
			input = input.substring(0, input.length() - 1);
			
			int sum = romanToDecimal(input.split("\\+")[0]) + romanToDecimal(input.split("\\+")[1]);
			
			if (sum <= 1000)
				System.out.println(input + "=" + IntegerToRomanNumeral(sum));
			else
				System.out.println(input + "=CONCORDIA CUM VERITATE");
		}
	}
}
