
/*
ID: 34870941
LANG: JAVA
TASK: gift1
*/

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.ArrayList;

public class USACO_gift1 {

	public static void main(String[] args) {
		try{
			//Scanner input = new Scanner(new File("gift1.in"));
			Scanner input = new Scanner(System.in);
			BufferedWriter output = new BufferedWriter(new FileWriter("gift1.out"));
			
			int friendCount = input.nextInt();
			//input.nextLine();
			
			ArrayList<String> friendName = new ArrayList<String>();
			ArrayList<Integer> balance = new ArrayList<Integer>();
			
			for (int i=0; i<friendCount; i++){
				String name = input.nextLine();
				
				friendName.add(name);
				balance.add(0);
			}
			
			while(true){
				String currentName = input.nextLine();
				
				int totalMoney = input.nextInt();
				int totalPeople = input.nextInt();
				
				if (totalMoney == 0 && totalPeople == 0) break;
				
				int eachPerson = (int)(totalMoney / totalPeople);
				int moneyGiven = eachPerson * totalPeople;
				
				int accountBal = balance.get(friendName.indexOf(currentName));
				accountBal -= moneyGiven;
				balance.set(friendName.indexOf(currentName), accountBal);
				
				for (int i=0; i<totalPeople; i++){
					String name = input.nextLine();
					
					int nCurrentBal = balance.get(friendName.indexOf(name));
					nCurrentBal += eachPerson;
					balance.set(friendName.indexOf(name), nCurrentBal);
				}
			}
			
			for (int i=0; i<friendName.size(); i++){
				String fName = friendName.get(i);
				int fBalance = balance.get(i);
				
				System.out.print(fName + " " + Integer.toString(fBalance) + "\n");
			}
			
			input.close();
			output.close();
		} catch (Exception ex){
			
		}

	}

}
