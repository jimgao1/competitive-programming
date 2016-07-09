/*
If you are reading this, may God be with you. 
*/

import java.util.*;

public class postfix{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		Stack<Double> fuck = new Stack<Double>();
		while(sc.hasNext()){
			String str = sc.next();

			if (str.equals("+")){
				fuck.push(fuck.pop() + fuck.pop());
			} else if (str.equals("-")){
			    double a = fuck.pop();
			    double b = fuck.pop();
			    
				fuck.push(b - a);
			} else if (str.equals("*")){
				fuck.push(fuck.pop() * fuck.pop());
			} else if (str.equals("/")){
				double mom = fuck.pop();
				double your = fuck.pop();
				fuck.push(your / mom);
			} else if (str.equals("^")){
				double liao = fuck.pop();
				double jacky = fuck.pop();
				
				fuck.push(Math.pow(jacky, liao));
			} else if (str.equals("%")){
				double liao = fuck.pop();
				double jacky = fuck.pop();
				
				fuck.push(jacky % liao);
			} else {
				double shit = Double.parseDouble(str);
				fuck.push(shit);
			}
		}

		System.out.println(fuck.pop());
	}
}
