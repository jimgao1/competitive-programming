import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;

import java.util.Queue;
import java.util.LinkedList;

public class graph3p1 {
	
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
	
	public static Map<Integer, ArrayList<Integer>> adjList;
	
	public static boolean full(boolean[] visited){
		for (boolean b : visited)
			if (b) return false;
		return true;
	}

	public static void main(String[] args){
		FastReader keyboard = new FastReader();
		
		int nodeCount = keyboard.nextInt();
		int edgeCount = keyboard.nextInt();
		
		adjList = new HashMap<Integer, ArrayList<Integer>>();
		
		for (int i=0; i<nodeCount; i++)
			adjList.put(i, new ArrayList<Integer>());
		
		for (int i=0; i<edgeCount; i++){
			int nodeA = keyboard.nextInt() - 1;
			int nodeB = keyboard.nextInt() - 1;
			
			adjList.get(nodeA).add(nodeB);
			adjList.get(nodeB).add(nodeA);
		}
		
		boolean[] visited = new boolean[nodeCount];
		int[] nodeTime = new int[nodeCount];
		
		for (int i=0; i<nodeCount; i++)
			nodeTime[i] = -1;
		
		Queue<Integer> bfs = new LinkedList<Integer>();
		
		int salesmanCount = keyboard.nextInt();
		for (int i=0; i<salesmanCount; i++){
			int sal = keyboard.nextInt() - 1;
			bfs.add(sal);
			nodeTime[sal] = 0;
			visited[sal] = true;
		}
		
		while(!bfs.isEmpty()){
			int currentNode = bfs.remove();

			for (int newNode: adjList.get(currentNode)){
				if (!visited[newNode]){
					nodeTime[newNode] = nodeTime[currentNode] + 1;
					visited[newNode] = true;
					bfs.add(newNode);
				}
			}
		}
		
		int max = 0;
		for (int n : nodeTime) max = Math.max(max, n);
		System.out.println(max);
	}
}
