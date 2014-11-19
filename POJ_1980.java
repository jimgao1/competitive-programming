/*
 * 		PROGRAM "MAYBE" WORKING
 * 		Problem URL: http://poj.org/problem?id=1980
 */

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

public class POJ_1980{
	
	public static class Fraction{
		public int number1;
		public int number2;
		
		public Fraction(int a, int b){
			this.number1 = a;
			this.number2 = b;
		}
		
		public double getValue(){
			return (double)(this.number1) / this.number2;
		}
		
	}
	
	public static class SearchState{
		public ArrayList<Fraction> fractions;
		
		public SearchState(){
			fractions = new ArrayList<Fraction>();
		}
		
		public int getFractionCount(){
			return this.fractions.size();
		}
		
		public double getTotalValue(){
			double sum = 0;
			for (int i=0; i<getFractionCount(); i++){
				sum += fractions.get(i).getValue();
			}
			
			return sum;
		}
		
		public int getMultiplication(){
			int result = 1;
			for (int i=0; i<getFractionCount(); i++){
				result *= fractions.get(i).number2;
			}
			
			return result;
		}
		
		public SearchState fork(){
			SearchState n = new SearchState();
			n.fractions = new ArrayList<Fraction>();
			
			for (int i=0; i<fractions.size(); i++){
				n.fractions.add(fractions.get(i));
			}
			
			return n;
		}
		
		public void printInfo(){

			System.out.println();
			System.out.println("-SearchState Instance-");
			System.out.println("Fractions: " + this.fractions.size());
			
			for (int i=0; i<this.fractions.size(); i++){
				System.out.println("Fraction #" + i + ": " + this.fractions.get(i).number1 + " / " + this.fractions.get(i).number2);
			}
			
			System.out.println("\n-End of Instance");
			
		}
	}
	
	public static void runSearch(){
		SearchState s = searchQueue.poll();
		
		//s.printInfo();
		
		/*
		 * 		Check if valid
		 */
		
		if (s.getFractionCount() <= globalFractionLimit &&
				s.getMultiplication() <= globalMultiplicationLimit){
			
			if (s.getTotalValue() == globalFractionTarget.getValue()) {
				success.add(s);
				return;
			}
		}
		
		/*
		 * 		"Leaf cutting" step
		 */
		
		//if (globalFractionLimit - s.getFractionCount() == 0) return;
		//if (globalFractionTarget.getValue() - s.getTotalValue() 
		//		> globalFractionLimit - s.getFractionCount()) return;
		if (globalFractionTarget.getValue() < s.getTotalValue()) return;
		if (s.getFractionCount() > globalFractionLimit) return;
		if (s.getMultiplication() > globalMultiplicationLimit) return;
		
		
		int maxDenominator = (int)globalMultiplicationLimit / s.getMultiplication();
		
		for (int i=s.fractions.get(s.fractions.size() - 1).number2; i<(maxDenominator + 1); i++){
			Fraction f = new Fraction(1, i);
			SearchState st = s.fork();
			st.fractions.add(f);
			searchQueue.add(st);
		}
		
		return;
		
	}
	
	public static Queue<SearchState> searchQueue;
	public static ArrayList<SearchState> success;
	public static int globalFractionLimit;
	public static int globalMultiplicationLimit;
	
	public static Fraction globalFractionTarget;
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		searchQueue = new LinkedList<SearchState>();
		success = new ArrayList<SearchState>();
		
		globalFractionTarget = new Fraction(keyboard.nextInt(), keyboard.nextInt());
		globalMultiplicationLimit = keyboard.nextInt();
		globalFractionLimit = keyboard.nextInt();
		
		for (int i=2; i<globalMultiplicationLimit; i++){
			Fraction f = new Fraction(1, i);
			SearchState s = new SearchState();
			s.fractions.add(f);
			
			searchQueue.add(s);
		}
		
		while(!searchQueue.isEmpty()){
			runSearch();
		}
		
		for (int i=0; i<success.size(); i++){
			System.out.println("Solution #" + i);
			System.out.println("Fraction Count: " + success.get(i).fractions.size());
			
			for (int j=0; j<success.get(i).fractions.size(); j++){
				System.out.printf("%d / %d, " , success.get(i).fractions.get(j).number1,
						success.get(i).fractions.get(j).number2);  
			}
			
			System.out.println("\n");
		}
	}
}
