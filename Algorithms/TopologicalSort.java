import java.util.Scanner;
import java.util.LinkedList;

public class TopologicalSort {
	
	
	/*
	 * 	The main topological sorting function
	 */
	public static LinkedList<Integer> topologicalSort(int[][] matrix){
		matrix = (int[][]) matrix.clone();
		LinkedList<Integer> result = new LinkedList<Integer>();
		boolean[] visited = new boolean[matrix.length];
		
		while(true){
			boolean allVisited = true;
			
			for (int i=0; i<matrix.length; i++)
				if (!visited[i]) allVisited = false;
			
			if (allVisited) return result;
			
			LinkedList<Integer> inDegree = new LinkedList<Integer>();
			
			for (int i=0; i<matrix.length; i++){
				if (!visited[i]){
					int indeg = 0;
					
					for (int j=0; j<matrix.length; j++)
						if (matrix[j][i] == 1) indeg += 1;
					
					if (indeg == 0) inDegree.add(i);
				}
				
			}
			
			/*
			 * 	If there is no node with a in degree 0,
			 * 	then there is a cycle inside the directed graph. 
			 */
			if (inDegree.isEmpty()) return null;
			
			for (int i=0; i<inDegree.size(); i++){
				for (int j=0; j<matrix.length; j++){
					matrix[inDegree.get(i)][j] = -1;
					matrix[j][inDegree.get(i)] = -1;
				}
				visited[inDegree.get(i)] = true;
				result.add(inDegree.get(i));
			}
			
		}
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		while(true){
			int nodeCount = keyboard.nextInt();
			int comparasonCount = keyboard.nextInt();
			
			if (nodeCount == 0 && comparasonCount == 0) break;
			
			int[][] matrix = new int[nodeCount][nodeCount];
			
			for (int i=0; i<nodeCount; i++)
				for (int j=0; j<nodeCount; j++)
					matrix[j][i] = -1;
			
			for (int i=0; i<comparasonCount; i++){
				int nodeA = keyboard.nextInt() - 1;
				int nodeB = keyboard.nextInt() - 1;
				
				matrix[nodeA][nodeB] = 1;
			}
			
			LinkedList<Integer> result = topologicalSort(matrix);
			
			if (result != null)
				for (int n : result)
					System.out.print(n + 1 + " ");
		}
	}
}
