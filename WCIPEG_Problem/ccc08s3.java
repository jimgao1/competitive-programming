import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Queue;
import java.util.StringTokenizer;

public class ccc08s3 {
	
	public static final int[][] bidirectional = {
		{0, 1}, {0, -1}, {1, 0}, {-1, 0}
	};
	
	public static final int[][] vertical = {
		{0, 1}, {0, -1}
	};
	
	public static final int[][] horizontal = {
		{1, 0}, {-1, 0}
	};
	
	public static class Point{
		public int x;
		public int y;
		
		public Point(int a, int b){
			this.x = a;
			this.y = b;
		}
	}
	
	public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            try {
                br = new BufferedReader(new InputStreamReader(System.in));
            } catch (Exception ex){}
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
}
	
	public static void main(String[] args){
		FastScanner keyboard = new FastScanner();
		
		int caseCount = keyboard.nextInt();
		while(caseCount-- != 0){
			int sizeY = keyboard.nextInt();
			int sizeX = keyboard.nextInt();
			
			char[][] map = new char[sizeX][sizeY];
			
			for (int i=0; i<sizeY; i++){
				String line = keyboard.next();
				for (int j=0; j<sizeX; j++)
					map[j][i] = line.charAt(j);
			}
			
			boolean[][] visited = new boolean[sizeX][sizeY];
			int[][] minSteps = new int[sizeX][sizeY];
			
			for (int i=0; i<sizeX; i++)
				for (int j=0; j<sizeY; j++)
					minSteps[i][j] = Integer.MAX_VALUE;
			
			minSteps[0][0] = 1;
			
			Queue<Point> bfs = new LinkedList<Point>();
			bfs.add(new Point(0, 0));
			
			while(!bfs.isEmpty()){
				Point current = bfs.remove();
				int currentX = current.x;
				int currentY = current.y;
				
				if (visited[currentX][currentY]) continue;
				visited[currentX][currentY] = true;
				
				if (map[currentX][currentY] == '*')
					continue;
				else if (map[currentX][currentY] == '+')
					for (int i=0; i<4; i++){
						int newX = currentX + bidirectional[i][0];
						int newY = currentY + bidirectional[i][1];
						
						if (newX < 0 || newX >= sizeX) continue;
						if (newY < 0 || newY >= sizeY) continue;
						
						if (visited[newX][newY]) continue;
						if (map[newX][newY] == '*') continue;
						
						if (minSteps[newX][newY] <= minSteps[currentX][currentY] + 1) continue;
						minSteps[newX][newY] = minSteps[currentX][currentY] + 1;
						
						bfs.add(new Point(newX, newY));
					}
				else if (map[currentX][currentY] == '-')
					for (int i=0; i<2; i++){
						int newX = currentX + horizontal[i][0];
						int newY = currentY + horizontal[i][1];
						
						if (newX < 0 || newX >= sizeX) continue;
						if (newY < 0 || newY >= sizeY) continue;
						
						if (visited[newX][newY]) continue;
						if (map[newX][newY] == '*') continue;
						
						if (minSteps[newX][newY] <= minSteps[currentX][currentY] + 1) continue;
						minSteps[newX][newY] = minSteps[currentX][currentY] + 1;
						
						bfs.add(new Point(newX, newY));
					}
				else if (map[currentX][currentY] == '|')
					for (int i=0; i<2; i++){
						int newX = currentX + vertical[i][0];
						int newY = currentY + vertical[i][1];
						
						if (newX < 0 || newX >= sizeX) continue;
						if (newY < 0 || newY >= sizeY) continue;
						
						if (visited[newX][newY]) continue;
						
						if (map[newX][newY] == '*') continue;
						
						if (minSteps[newX][newY] <= minSteps[currentX][currentY] + 1) continue;
						minSteps[newX][newY] = minSteps[currentX][currentY] + 1;
						
						bfs.add(new Point(newX, newY));
					}
				
			}
			
			if (minSteps[sizeX - 1][sizeY - 1] == Integer.MAX_VALUE)
				System.out.println(-1);
			else
				System.out.println(minSteps[sizeX - 1][sizeY - 1]);
		}
	}
}
