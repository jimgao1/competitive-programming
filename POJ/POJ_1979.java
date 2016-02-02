import java.util.Scanner;

public class POJ_1979 {
	
	public static char[][] board;
	public static boolean[][] visited;
	
	public static int sizeX;
	public static int sizeY;
	
	public static int initialX;
	public static int initialY;
	
	public static int locationsReached;
	
	public static void search(int currentX, int currentY){
		if (currentX < 0 || currentX >= sizeX) return;
		if (currentY < 0 || currentY >= sizeY) return;
		
		if (visited[currentX][currentY]) return;
		if (board[currentX][currentY] == '#') return;
		
		visited[currentX][currentY] = true;
		locationsReached += 1;
		
		search(currentX, currentY + 1);
		search(currentX, currentY - 1);
		search(currentX + 1, currentY);
		search(currentX - 1, currentY);
		
		return;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		while(true){
			sizeX = keyboard.nextInt();
			sizeY = keyboard.nextInt();
			
			keyboard.nextLine();
			
			if (sizeX == 0 && sizeY == 0) break;
			
			initialX = -1;
			initialY = -1;
			
			board = new char[sizeX][sizeY];
			visited = new boolean[sizeX][sizeY];
			locationsReached = 0;
			
			for (int i=0; i<sizeY; i++){
				String line = keyboard.nextLine();
				for (int j=0; j<sizeX; j++){
					board[j][i] = line.charAt(j);
					
					if (board[j][i] == '@'){
						initialX = j;
						initialY = i;
					}
				}
			}
			
			search(initialX, initialY);
			
			System.out.println(locationsReached);
			
		}
	}
}
