
public class MathStuff {
	
	public static char[] digits = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'X', 'Y', 'Z'
	};
	
	public static double logBase(int num, int base){
		return Math.log(num) / Math.log(base);
	}
	
	public static int getValue(char c){
		for (int i=0; i<digits.length; i++) if (digits[i] == c) return i;
		return 0;
	}
	
	public static int baseToDec(String num, int base){
		int result = 0;
		
		for (int i=0; i<num.length(); i++){
			result += getValue(num.charAt(i)) * Math.pow(base, num.length() - i - 1);
		}
		
		return result;
	}
	
	public static String decToBase(int num, int base){
		String result = "";
		int d = (int)Math.ceil((Math.log(num) / Math.log(base)));
		
		for (int i=d - 1; i>=0; i--){
			int cur = (int) Math.floor(num / Math.pow(base, i));
			num -= cur * Math.pow(base, i);
			
			result += (char)(digits[cur]);
		}
		
		return result;
	}
	
	public static String baseToBase(String num, int baseA, int baseB){
		return decToBase(baseToDec(num, baseA), baseB);
	}
	
}
