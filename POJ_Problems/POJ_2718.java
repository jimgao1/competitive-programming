import java.util.Scanner;
import java.util.ArrayList;

public class Main {
	
	public static ArrayList<Integer> number1;
	public static ArrayList<Integer> number2;
	
	public static void generateNumbers(String n1, String n2, ArrayList<Integer> numbers){
		if (numbers.isEmpty()){
			if (!n1.equals("") && !n2.equals("")){
				if (!number1.contains(Integer.parseInt(n1))){
					number1.add(Integer.parseInt(n1));
					number2.add(Integer.parseInt(n2));
				}
			}
			return;
		}
		
		for (int i=0; i<numbers.size(); i++){
			int currentDigit = numbers.get(i);
			
			if (n1.length() >= 1 || currentDigit != 0){
				ArrayList<Integer> newArr = (ArrayList<Integer>) numbers.clone();
				newArr.remove(i);
				
				generateNumbers(n1 + Integer.toString(currentDigit), n2, newArr);
			}
			
			if (n2.length() >= 1 || currentDigit != 0){
				ArrayList<Integer> newArr = (ArrayList<Integer>) numbers.clone();
				newArr.remove(i);
				
				generateNumbers(n1, n2 + Integer.toString(currentDigit), newArr);
			}
		}
		
		return;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int caseCount = keyboard.nextInt();
		keyboard.nextLine();
		
		while(caseCount-- != 0){
			String[] strDigits = keyboard.nextLine().split(" ");
			ArrayList<Integer> digits = new ArrayList<Integer>();
			
			for (int i=0; i<strDigits.length; i++)
				digits.add(Integer.parseInt(strDigits[i]));
			
			number1 = new ArrayList<Integer>();
			number2 = new ArrayList<Integer>();
			
			generateNumbers("", "", digits);
			
			int minDifference = Integer.MAX_VALUE;
			
			for (int i=0; i<number1.size(); i++){
				minDifference = Math.min(minDifference, Math.abs(number1.get(i) - number2.get(i)));
			}
			
			System.out.println(minDifference);
		}
	}
}
