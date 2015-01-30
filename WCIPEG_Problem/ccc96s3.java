

import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;

public class ccc96s3 {
	
	public static ArrayList<String> results;
	
	public static void rec(int d, int o, String s){
		if (d == 0){
			if (o == 0)
				results.add(s);
			return;
		}
		
		if (o < 0) return;
		
		rec(d - 1, o, s + "0");
		rec(d - 1, o - 1, s + "1");
		
		return;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int caseCount = keyboard.nextInt();
		
		while(caseCount-- != 0){
			System.out.println("The bit patterns are");
			
			results = new ArrayList<String>();
			
			int digits = keyboard.nextInt();
			int ones = keyboard.nextInt();
			
			rec(digits, ones, "");
			
			Collections.sort(results);
			Collections.reverse(results);
			
			for (String s : results)
				System.out.println(s);
			
			System.out.println();
		}
	}
}
