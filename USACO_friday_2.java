/*
ID: 34870941
LANG: JAVA
TASK: friday
*/

import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileWriter;

public class USACO_friday_2 {

	public static int getDays(int month, boolean leapYear){
		if (month == 1 || month == 3 || month == 5 ||
				month == 7 || month == 8 || month == 10 ||
				month == 12) return 31;
		
		if (month == 2){
			if (leapYear) return 29;
			return 28;
		}
		
		return 30;
	}
	
	public static void main(String[] args) {
		try{
			Scanner keyboard = new Scanner(new File("friday.in"));
			PrintWriter output = new PrintWriter(new FileWriter("friday.out"));
			
			int yearCount = keyboard.nextInt();
			int currentWeekday = 1;
			int[] weekdayOccurances = new int[7];
			
			for (int currentYear = 1900; currentYear <= (1900 + yearCount - 1); currentYear += 1){
				boolean leapYear = false;
				if (currentYear % 4 == 0 && currentYear % 100 != 0) leapYear = true;
				if (currentYear % 400 == 0) leapYear = true;
				
				for (int currentMonth = 1; currentMonth <= 12; currentMonth += 1){
					int numberOfDays = getDays(currentMonth, leapYear);
					
					for (int currentDay = 1; currentDay <= numberOfDays; currentDay += 1){
						if (currentDay == 13) weekdayOccurances[currentWeekday] += 1;
						currentWeekday += 1;
						if (currentWeekday == 7) currentWeekday = 0;
					}
				}
			}
			
			output.write(weekdayOccurances[6] + " ");
			for (int i=0; i<5; i++){
				output.write(weekdayOccurances[i] + " ");
			}
			output.write(weekdayOccurances[5] + "\n");
			
			keyboard.close();
			output.close();
		}  catch (Exception ex){}
	} 
}


