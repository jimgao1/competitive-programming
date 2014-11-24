import java.util.Scanner;
import java.util.ArrayList;

public class DiskCapacity_DynamicProgramming {
	
	/*
	 * 		Dynamic Programming solution for 0/1 knapsack problem
	 * 
	 * 		by Jim Gao
	 */
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int fileCount = keyboard.nextInt();
		int diskSize = keyboard.nextInt();
		
		ArrayList<Integer> fileSizes = new ArrayList<Integer>();
		
		
		for (int i=0; i<fileCount; i++){
			int currentFileSize = keyboard.nextInt();
			fileSizes.add(currentFileSize);
		}
		
		int[][] f = new int[diskSize][fileCount];
		int[] accumulatedSize = new int[fileCount];
		
		int currentSize = 0;
		
		for (int i=0; i<fileCount; i++){
			currentSize += fileSizes.get(i);
			accumulatedSize[i] = currentSize;
		}
		
		for (int i=0; i<fileCount; i++){
			for (int j=0; j<diskSize; j++){
				if (j > accumulatedSize[i]){
					f[j][i] = accumulatedSize[i];
				} else {
					if (i == 0){
						f[j][i] = 0;
					} else {
						f[j][i] = f[j][i - 1];
					}	
				}
			}
		} 
		
		System.out.println(f[diskSize - 1][fileCount - 1]);
		
	}
}
