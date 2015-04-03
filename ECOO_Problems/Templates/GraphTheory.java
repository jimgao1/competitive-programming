import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;

public class GraphTheory {
	public static class Edge implements Comparable<Edge>{
		int source, target, cost;
		Edge(int source, int target, int cost){
			this.source = source;
			this.target = target;
			this.cost = cost;
		}
		@Override
		public int compareTo(Edge e) {
			return cost - e.cost; 
		}
	}
	
	/*------------------------------------------------------------------*/
	//BFS
	public static int bfs(boolean[][] graph, int nodeCount, int start, int goal){
		boolean[] visited = new boolean[nodeCount];
		int[] dist = new int[nodeCount];
		Queue<Integer> q = new LinkedList<>();
		q.add(start);
		visited[start] = true;
		while(!q.isEmpty()){
			int cur = q.remove();
			if(cur == goal)
				break;
			for(int i = 0; i < nodeCount; i++){
				if(graph[cur][i] && !visited[i]){
					q.add(i);
					visited[i] = true;
					dist[i] = dist[cur] + 1;
				}
			}
		}
		return dist[goal];
	}
	
	/*------------------------------------------------------------------*/
	//SPFA
	public static int[] spfa(int[][] graph, int nodeCount, int start){
		int[] distance = new int[nodeCount];
		boolean[] contains = new boolean[nodeCount];
		Arrays.fill(distance, Integer.MAX_VALUE);
		
		Queue<Integer> q = new LinkedList<>();
		distance[start] = 0;
		q.add(start);
		
		while(!q.isEmpty()){
			int cur = q.remove();
			contains[cur] = false;
			for(int i = 0; i < nodeCount; i++){
				if(graph[cur][i] != 0 && distance[i] > distance[cur] + graph[cur][i]){
					distance[i] = distance[cur] + graph[cur][i];
					if(!contains[i]){
						q.add(i);
						contains[i] = true;
					}
				}
			}
		}
		return distance;
	}
	
	
	/*------------------------------------------------------------------*/
	//Toplogical Sort
	public static ArrayList<Integer> TopologicalSort(int[][] graph, int nodeCount){
		ArrayList<Integer> sorted = new ArrayList<Integer>();
		int[] count = new int[nodeCount];
		for(int i = 0; i < nodeCount; i++){
			for(int x = 0; x < nodeCount; x++){
				if(graph[i][x] > 0){
					count[x]++;
				}
			}
		}
		Queue<Integer> q = new LinkedList<>();
		for(int i = 0; i < nodeCount; i++){
			if(count[i] == 0)
				q.add(i);
		}
		while(!q.isEmpty()){
			int node = q.remove();
			sorted.add(node);
			for(int i = 0; i < nodeCount; i++){
				if(graph[node][i] != 0){
					graph[node][i] = 0;
					count[i]--;
					boolean no = true;
					if(count[i] != 0){
						no = false;
					}
					if(no)
						q.add(i);
				}
			}
		}
		return sorted;
	}
	
	/*------------------------------------------------------------------*/
	//Prims Algorithm
	//V^2 Version
	//Adjacency matrix
	public static int[] PrimsV2(int[][] graph, int root, int nodeCount, int edgeCount){
		boolean[] visited = new boolean[nodeCount];
		int[] prev = new int[nodeCount]; //connecting path of node
		int[] dist = new int[nodeCount]; //weight of connecting path
		Arrays.fill(dist, Integer.MAX_VALUE);
		int mst = 0;
		dist[root] = 0;
		for(int i = 0; i < nodeCount; i++){
			int cur = -1;
			int min = Integer.MAX_VALUE;
			for(int x = 0; x < nodeCount; x++){
				if(dist[i] < min){
					min = dist[i];
					cur = i;
				}
			}
			if(cur == -1)
				break;
			visited[cur] = true;
			for(int x = 0; x < nodeCount; x++){
				if(graph[cur][x] != 0){
					if(dist[x] > graph[cur][x]){
						dist[x] = graph[cur][x];
						prev[x] = cur;
					}
				}
			}
		}
		return prev;
	}
	
	//(E + V) logV Version //Adjacency list
	//Can also return prev to generate the graph
	//Can also return weight to get all the weights of the graph
	public static int PrimsEVLogV(Map<Integer, ArrayList<Edge>> graph, int root, int nodeCount, int edgeCount){
		boolean[] visited = new boolean[nodeCount];
		int[] prev = new int[nodeCount]; //connecting path of node
		int[] weight = new int[nodeCount]; //weight of connecting path
		int mst = 0;
		PriorityQueue<Edge> q = new PriorityQueue<>();
		q.add(new Edge(root, root, 0));
		while(!q.isEmpty()){
			Edge cur = q.remove();
			if(visited[cur.target])
				continue;
			visited[cur.target] = true;
			prev[cur.target] = cur.source;
			weight[cur.target]  = cur.cost;
			mst += cur.cost;
			for(Edge e : graph.get(cur.target)){
				if(!visited[e.target])
					q.add(e);
			}
		}
		
		for(int i = 0; i < nodeCount; i++){
			if(!visited[i]) //Use v^2 to find minimum spanning forest if needed
				return -1; //That means an mst cannot be created
		}
		
		return mst;
	}
}
