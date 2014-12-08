import java.util.Scanner;
import java.math.BigDecimal;

public class POJ_1001 {
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		while(keyboard.hasNext()){
			BigDecimal number = keyboard.nextBigDecimal();
			
			number = number.pow(keyboard.nextInt());
			
			String result = number.stripTrailingZeros().toPlainString();
			
			if (result.charAt(0) == '0'){
				result = result.substring(1);
			}
			
			System.out.println(result);
		}
	}
}
