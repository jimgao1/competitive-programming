import java.util.Scanner;

public class Matrix_Chain_Recursive {
	
	public static int[] numbers;
	
	public static int matrixChainOrder(int startIndex, int endIndex){
		if (startIndex == endIndex) return 0;
		
		int min = Integer.MAX_VALUE;
		int count = -1;
		
		for (int i = startIndex; i < endIndex; i++){
			count = matrixChainOrder(startIndex, i) + 
					matrixChainOrder(i + 1, endIndex) + 
					numbers[startIndex - 1] + numbers[i] + numbers[endIndex];
			
			if (count < min)
				min = count;
		}
		
		return min;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		System.out.print("Number Count: ");
		int numberCount = keyboard.nextInt();
		
		numbers = new int[numberCount];
		
		for (int i=0; i<numberCount; i++)
			numbers[i] = keyboard.nextInt();
		
		System.out.printf("Min Multiplication Result: %d\n", 
				matrixChainOrder(1, numberCount - 1));
	}
}
