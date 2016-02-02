import java.io.File;
import java.util.Scanner;

public class Problem_1 {
	
	public static void main(String[] args) throws Exception{
		Scanner keyboard = new Scanner(new File("input3.txt"));
		
		for (int i=0; i<5; i++){
			int sizeY = keyboard.nextInt();
			int sizeX = keyboard.nextInt();
			int pLength = keyboard.nextInt();
			int qLength = keyboard.nextInt();
			
			for (int j=0; j<qLength; j++){
				for (int k=0; k<qLength * 2 + pLength * 2 + sizeX; k++){
					System.out.print("#");
				}
				System.out.println();
			}
			
			for (int k=0; k<pLength; k++){
			
				for (int j=0; j<qLength; j++) System.out.print("#");
				
				for (int j=0; j<pLength * 2 + sizeX; j++)
					System.out.print("+");
				
				for (int j=0; j<qLength; j++) System.out.print("#");
				
				System.out.println();
			}
			
			for (int j=0; j<sizeY; j++){
				for (int k=0; k<qLength; k++) System.out.print("#");
			
				for (int k=0; k<pLength; k++) System.out.print("+");
				
				for (int k=0; k<sizeX; k++) System.out.print(".");
				
				for (int k=0; k<pLength; k++) System.out.print("+");
				
				for (int k=0; k<qLength; k++) System.out.print("#");
				
				System.out.println();
			}
			
			for (int k=0; k<pLength; k++){
				
				for (int j=0; j<qLength; j++) System.out.print("#");
				
				for (int j=0; j<pLength * 2 + sizeX; j++)
					System.out.print("+");
				
				for (int j=0; j<qLength; j++) System.out.print("#");
				
				System.out.println();
			}
			
			for (int j=0; j<qLength; j++){
				for (int k=0; k<qLength * 2 + pLength * 2 + sizeX; k++){
					System.out.print("#");
				}
				System.out.println();
			}
			
			System.out.println();
			
		}
	}
}
