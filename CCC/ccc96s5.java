import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class ccc98s5 {
	
	public static class Point{
		public int x;
		public int y;
		
		public Point(){}
		public Point(int x1, int y1){
			this.x = x1;
			this.y = y1;
		}
		
	}
	
	public static final int[][] moves = {
		{0, 1}, {0, -1}, {1, 0}, {-1, 0}
	};
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		int caseCount = keyboard.nextInt();
		
		while(caseCount-- != 0){
			int mapSize = keyboard.nextInt();
			
			int[][] oxygen = new int[mapSize][mapSize];
			int[][] minOxygen = new int[mapSize][mapSize];
			boolean[][] visited = new boolean[mapSize][mapSize];
			
			for (int i=0; i<mapSize; i++)
				for (int j=0; j<mapSize; j++){
					oxygen[i][j] = keyboard.nextInt();
					minOxygen[i][j] = Integer.MAX_VALUE;
				}

			
			int limit = oxygen[0][0];
			minOxygen[0][0] = 0;
			
			Queue<Point> bfs = new LinkedList<Point>();
			bfs.add(new Point(0, 0));
			
			while(!bfs.isEmpty()){
				Point p = bfs.remove();
				
				if (visited[p.x][p.y]) continue;
				visited[p.x][p.y] = true;
				
				for (int i=0; i<4; i++){
					int newX = p.x + moves[i][0];
					int newY = p.y + moves[i][1];
					
					if (newX < 0 || newX >= mapSize) continue;
					if (newY < 0 || newY >= mapSize) continue;
					
					if (visited[newX][newY]) continue;
					
					if (Math.abs(oxygen[newX][newY] - oxygen[p.x][p.y]) > 2) continue;
					
					Point newP = new Point(newX, newY);
					
					if (oxygen[p.x][p.y] > limit || oxygen[newX][newY] > limit) 
						minOxygen[newX][newY] = minOxygen[p.x][p.y] + 1;
					else
						minOxygen[newX][newY] = minOxygen[p.x][p.y];
					
					bfs.add(newP);
				}
			}
			
			if (minOxygen[mapSize - 1][mapSize - 1] == Integer.MAX_VALUE){
				System.out.println("CANNOT MAKE THE TRIP");
			} else {
				System.out.println(minOxygen[mapSize - 1][mapSize - 1]);
			}
		}
	}
}
