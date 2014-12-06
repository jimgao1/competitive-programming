import java.util.Scanner;
import java.util.ArrayList;

public class String_Permutations {
	
	/*
	 * 		This program makes permutations of strings
	 */
	
	public static void search(String done, ArrayList<Character> lettersLeft){
		if (lettersLeft.size() == 0){
			System.out.println(done);
			return;
		}
		
		for (int i=0; i<lettersLeft.size(); i++){
			ArrayList<Character> after = (ArrayList<Character>)(lettersLeft.clone());
			String d = done + after.get(i);
			after.remove(i);
			search(d, after);
		}
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		String n = keyboard.nextLine();
		ArrayList<Character> letters = new ArrayList<Character>();
		
		for (int i=0; i<n.length(); i++){
			letters.add(n.charAt(i));
		}
		
		search("", letters);
		
	}
}
