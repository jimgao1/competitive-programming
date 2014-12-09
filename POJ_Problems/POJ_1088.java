import java.util.Scanner;

public class POJ_1088 {
	
	/*
	 * 		NOT COMPLETE
	 */
	
	public static char[][] map;
	
	public static int sizeX;
	public static int sizeY;
	
	public static int getElement(int x, int y){
		try{
			return map[x][y];
		} catch (Exception ex){
			return -1;
		}
	}
	
	public static void search(int x, int y, int steps){
		if (x < 0 || x >= sizeX) return;
		if (y < 0 || y >= sizeY) return;
		if (steps > sizeX * sizeY) return;
		
		
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		sizeY = keyboard.nextInt();
		sizeX = keyboard.nextInt();
		
		keyboard.nextLine();
		
		map = new char[sizeX][sizeY];
		
		for (int i=0; i<sizeY; i++){
			String line = keyboard.nextLine();
			for (int j=0; j<sizeX; j++){
				map[j][i] = line.charAt(j);
			}
		}
	}
}
