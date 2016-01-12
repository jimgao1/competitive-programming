import java.util.Scanner;
import java.util.ArrayList;

public class DiskCapacity_Recursion {
	
	/*
	 * 		This is a classic knapsack problem. You can either
	 * 		pick up an item, or drop it.
	 * 
	 * 		To solve this problem using dynamic programming, 
	 * 		we need to define a function f. 
	 * 
	 * 		Definition of f(n):
	 * 
	 *			f(set of items, w);
	 *				is the maximum disk with a maximum
	 *				usage of the disk
	 *
	 *				meaning we have to fit the maximum
	 *				amount of files in the size of w
	 * 
	 */
	
	public static ArrayList<Integer> fileSize;
	
	public static int max(int a, int b){
		if (a > b) return a;
		return b;
	}
	
	
	
	public static int f(ArrayList<Integer> files, int size){
		ArrayList<Integer> solution1 = (ArrayList<Integer>) files.clone();
		ArrayList<Integer> solution2 = (ArrayList<Integer>) files.clone();
		
		int firstElement = files.get(0);
		
		/*
		 * 	Solution 1 - keeping the first element
		 */
		
		
		solution1.remove(0);
		
		
		/*
		 * 	Solution 2 - giving up the first file
		 */
		
		solution2.remove(0);
		
		return max(f(solution1, size - fileSize.get(firstElement)), 
				f(solution2, size));
	}
	
	public static void main(String[] args){
		
		
		Scanner keyboard = new Scanner(System.in);
		
		int fileCount = keyboard.nextInt();
		fileSize = new ArrayList<Integer>();
		ArrayList<Integer> files = new ArrayList<Integer>();
		
		System.out.println("File ID \tFile Size");
		System.out.println("=================================");
		
		for (int i=0; i<fileCount; i++){
			files.add(i);
			fileSize.add((int)(Math.random() * 40) + 1);
			System.out.println(i + "\t\t" + fileSize.get(i));
		}
		
		int maxSize = (int)(Math.random() * 100) + 1;
		
		System.out.println("File Limit: " + maxSize);
		
		System.out.println("Max File Size: " + f(files, maxSize));
	}
}
