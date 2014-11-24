/*
ID: 34870941
LANG: JAVA
TASK: ride
*/

import java.io.File;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Scanner;

public class USACO_ride {

	public static int getSum(String str){
		int valueSum = 1;
		
		for (int i=0; i<str.length(); i++){
			valueSum *= str.charAt(i) - 'A' + 1;
			valueSum = valueSum % 47;
		}
		
		return valueSum % 47;
	}
	
	
	
	public static void main(String[] args) {
		

		
		try{
			Scanner input = new Scanner(new File("ride.in"));
			BufferedWriter output = new BufferedWriter(new FileWriter("ride.out"));
			
			String name1 = input.nextLine();
			String name2 = input.nextLine();
			
			if (getSum(name1) == getSum(name2)){
				output.write("GO\n");
			} else {
				output.write("STAY\n");
			}
			
			input.close();
			output.close();
			
			
		} catch (Exception ex){
			ex.printStackTrace();
		}

	}
	

}
