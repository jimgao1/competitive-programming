import java.util.Scanner;

public class POJ_2386 {
	
	public static char[][] area;
	
	public static int sizeX;
	public static int sizeY;
	
	public static void search(int x, int y, int pondID){
		/*
		 * 	Check Bounds
		 */
		if (x < 0 || x >= sizeX) return;
		if (y < 0 || y >= sizeY) return;
		
		/*
		 * 	Check if current cell is valid
		 */
		if (area[x][y] != 'W') return;
		
		/*
		 * 	Set the current cell as visited
		 */
		area[x][y] = (char)(pondID);
		
		/*
		 * 	Search the nearby cells
		 */
		
		search(x, y - 1, pondID);
		search(x, y + 1, pondID);
		search(x - 1, y, pondID);
		search(x + 1, y, pondID);
		
		search(x - 1, y + 1, pondID);
		search(x - 1, y - 1, pondID);
		search(x + 1, y - 1, pondID);
		search(x + 1, y + 1, pondID);
		
		return;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		sizeY = keyboard.nextInt();
		sizeX = keyboard.nextInt();
		
		keyboard.nextLine();
		
		area = new char[sizeX][sizeY];
		
		for (int i=0; i<sizeY; i++){
			String line = keyboard.nextLine();
			for (int j=0; j<sizeX; j++){
				area[j][i] = line.charAt(j);
			}
		}
		
		int pondCount = 0;
		
		for (int i=0; i<sizeY; i++){
			for (int j=0; j<sizeX; j++){
				if (area[j][i] == 'W'){
					pondCount += 1;
					search(j, i, pondCount);
				}
			}
		}
		
		System.out.println(pondCount);
		
	}
}
