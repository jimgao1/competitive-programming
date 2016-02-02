import java.util.Scanner;

public class mockccc14s1 {
	
	public static int firstIndex(String source, String key){
		if (key.length() > source.length()) return -1;
		
		for (int i=0; i<source.length() - key.length() + 1; i++)
			if (source.substring(i, i + key.length()).equals(key))
				return i;
		
		return -1;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		String source = keyboard.nextLine();
		String key = keyboard.nextLine();
		
		source = new StringBuilder(source).reverse().toString();
		
		int firstIndex = firstIndex(source, key);
		
		if (firstIndex == -1)
			System.out.println(-1);
		else
			System.out.println(source.length() - firstIndex);
		
	}
}
