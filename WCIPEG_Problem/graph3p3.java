import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.PriorityQueue;

public class graph3p3 {
	public static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException ex) {
					ex.printStackTrace();
				}
			}

			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		public String nextLine() {
			try {
				return br.readLine();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
			return null;
		}
	}
	
	public static class Edge implements Comparable<Edge>{
		public int source;
		public int targetNode;
		public int cost;
		
		public Edge(){}
		public Edge(int a, int b, int c){
			this.source = a;
			this.targetNode = b;
			this.cost = c;
		}
		@Override
		public int compareTo(Edge arg0) {
			return this.cost - arg0.cost;
			
			
		}
	}
	
	public static void main(String[] args) {
		FastReader keyboard = new FastReader();
		
		int nodeCount = keyboard.nextInt();
		int edgeCount = keyboard.nextInt();
		
		int[][] matrix = new int[nodeCount][nodeCount];
		boolean[][] dangerous = new boolean[nodeCount][nodeCount];
		
		for (int i=0; i<nodeCount; i++)
			for (int j=0; j<nodeCount; j++)
				matrix[i][j] = -1;
		
		for (int i=0; i<edgeCount; i++){
			int nodeA = keyboard.nextInt() - 1;
			int nodeB = keyboard.nextInt() - 1;
			int cost = keyboard.nextInt();
			boolean dang = keyboard.nextInt() == 1;
			
			dangerous[nodeA][nodeB] = dang;
			dangerous[nodeB][nodeA] = dang;
			
			matrix[nodeA][nodeB] = cost;
			matrix[nodeB][nodeA] = cost;
			
			if (dang){
				matrix[nodeA][nodeB] += 10000;
				matrix[nodeB][nodeA] += 10000;
			}
		}
		
		/*
		 * 		Prims Algorithm
		 */
		
		boolean[] visited = new boolean[nodeCount];
		int totalLength = 0;
		int dangerousCount = 0;
		
		PriorityQueue<Edge> prims = new PriorityQueue<Edge>();
		
		prims.add(new Edge(-1, 0, 0));
		
		while(!prims.isEmpty()){
			
			boolean allVisited = true;
			for (boolean n : visited) if (!n) allVisited = false;
			
			if (allVisited) break;
			
			Edge e = prims.poll();
			
			int current = e.targetNode;
			int source = e.source;
			
			if (visited[current]) continue;
			visited[current] = true;
			
			totalLength += e.cost;
			if (source != -1 && dangerous[source][current]) dangerousCount += 1;
			
			
			for (int i=0; i<nodeCount; i++){
				if (!visited[i] && matrix[current][i] != -1){
					prims.add(new Edge(current, i, matrix[current][i]));
				}
			}
		}
		
		System.out.printf("%d %d\n", dangerousCount, totalLength - dangerousCount * 10000);
	}
}
