import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.Map;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.PriorityQueue;


public class ccc07s4 {
	
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
	
	public static void main(String[] args){
		FastReader keyboard = new FastReader();
		
		int nodeCount = keyboard.nextInt();
		
		int[] numberOfWays = new int[nodeCount];
		boolean[] visited = new boolean[nodeCount];
		Map<Integer, ArrayList<Integer>> adjList = new HashMap<Integer, ArrayList<Integer>>();
		
		for (int i=0; i<nodeCount; i++)
			adjList.put(i, new ArrayList<Integer>());
		
		for (int i=0; i<nodeCount; i++)
			numberOfWays[i] = 0;
		
		numberOfWays[0] = 1;
		
		while(true){
			int nodeA = keyboard.nextInt() - 1;
			int nodeB = keyboard.nextInt() - 1;
			
			if (nodeA == -1 && nodeB == -1) break;
			
			adjList.get(nodeA).add(nodeB);
		}
		
		PriorityQueue<Integer> bfs = new PriorityQueue<Integer>();
		bfs.add(0);
		
		while(!bfs.isEmpty()){
			int currentNode = bfs.remove();
			
			if (visited[currentNode]) continue;
			visited[currentNode] = true;
			
			for (int i=0; i<adjList.get(currentNode).size(); i++){
				int target = adjList.get(currentNode).get(i);
				
				if (!visited[target]){
					bfs.add(target);
					numberOfWays[target] += numberOfWays[currentNode];
				}
			}
		}
		
		System.out.println(numberOfWays[nodeCount - 1]);
	}
}
