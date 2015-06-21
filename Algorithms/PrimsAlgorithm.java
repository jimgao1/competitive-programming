import java.util.PriorityQueue;
import java.util.Scanner;

public class PrimsAlgorithm {

	public static class edge implements Comparable<edge> {
		int source, target, weight;

		public edge(int a, int b, int c) {
			this.source = a;
			this.target = b;
			this.weight = c;
		}

		public int compareTo(edge b) {
			return this.weight - b.weight;
		}
	}

	public static int[][] matrix;
	public static boolean[] visited;

	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);

		/*
		 * 	initialization
		 */
		int nodeCount = keyboard.nextInt();
		int edgeCount = keyboard.nextInt();

		matrix = new int[nodeCount][nodeCount];
		visited = new boolean[nodeCount];
		
		for (int i=0; i<nodeCount; i++)
			for (int j=0; j<nodeCount; j++)
				matrix[i][j] = -1;
		
		PriorityQueue<edge> pq = new PriorityQueue<edge>();

		for (int i = 0; i < edgeCount; i++) {
			int source, target, weight;
			source = keyboard.nextInt();
			target = keyboard.nextInt();
			weight = keyboard.nextInt();
			
			matrix[source][target] = weight;
			matrix[target][source] = weight;
		}
		
		/*
		 * 	actual algorithm
		 */
		
		int total = 0;
		pq.add(new edge(0, 0, 0));
		
		while(!pq.isEmpty()){
			edge current = pq.poll();
			if (visited[current.target]) continue;
			
			total += current.weight;
			visited[current.target] = true;
			
			for (int i = 0; i < nodeCount; i++) {
				if (!visited[i] && matrix[current.target][i] != -1){
					pq.add(new edge(current.target, i, matrix[current.target][i]));
				}
			}
		}
		
		System.out.println(total);
	}

}
