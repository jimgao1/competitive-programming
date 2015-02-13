import java.util.Scanner;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class ccc97s4 {
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int caseCount = keyboard.nextInt();
		keyboard.nextLine();
		
		while(caseCount-- != 0){
			Map<String, Integer> dictionary = new HashMap<String, Integer>();		
			ArrayList<String> lines = new ArrayList<String>();
			ArrayList<String> wordHistory = new ArrayList<String>();
			
			while(true){
				String t = keyboard.nextLine();
				if (t.length() > 0)
					lines.add(t);
				else
					break;
			}
			
			int wordCounter = 0;
			
			String result = "";
			
			for (int i=0; i<lines.size(); i++){
				String[] words = lines.get(i).split(" ");
				
				for (int j=0; j<words.length; j++){
					wordCounter += 1;
					
					if (dictionary.containsKey(words[j])){
						result += dictionary.get(words[j]) + 1 + " ";
						continue;
					}
					
					if (wordHistory.contains(words[j])){
						dictionary.put(words[j], wordHistory.indexOf(words[j]));
						result += dictionary.get(words[j]) + 1 + " ";
						continue;
					}
					
					result += words[j] + " ";
					wordHistory.add(words[j]);
					
				}
				
				result += "\n";
			}
			
			System.out.println(result);
		}
	}
}
