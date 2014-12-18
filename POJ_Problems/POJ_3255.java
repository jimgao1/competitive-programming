import java.util.Collections;
import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.Map;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Collections;

public class POJ_3255{
	
	public static class Node implements Comparable<Node>{
		
		public int nodeValue;
		public int nodeID;
		
		public Node(int id, int n){
			this.nodeID = id;
			this.nodeValue = n;
		}

		public int compareTo(Node someGayShit) {
			return this.nodeValue - someGayShit.nodeValue;
		}
		
	}
	
	public static int nodeCount;
	public static int edgeCount;
	public static int[][] matrix;
	public static boolean[] visited;
	
	public static Map<Integer, LinkedList<Integer>> adjList;
	public static Map<Integer, LinkedList<Integer>> shortestPath;
	
	public static PriorityQueue<Node> searchQueue;
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		nodeCount = keyboard.nextInt();
		edgeCount = keyboard.nextInt();
		
		matrix = new int[nodeCount][nodeCount];
		visited = new boolean[nodeCount];
		
		adjList = new HashMap<Integer, LinkedList<Integer>>();
		shortestPath = new HashMap<Integer, LinkedList<Integer>>();
		
		searchQueue = new PriorityQueue<Node>();
		
		
		for (int i=0; i<nodeCount; i++){
			adjList.put(i, new LinkedList<Integer>());
			shortestPath.put(i, new LinkedList<Integer>());
		}
		
		for (int i=0; i<edgeCount; i++){
			int sourceNode = keyboard.nextInt() - 1;
			int targetNode = keyboard.nextInt() - 1;
			int pathLength = keyboard.nextInt();
			
			matrix[sourceNode][targetNode] = pathLength;
			matrix[targetNode][sourceNode] = pathLength;
			
			adjList.get(sourceNode).add(targetNode);
			adjList.get(targetNode).add(sourceNode);
		}
		
		
		visited[0] = true;
		searchQueue.add(new Node(0, 0));
		
		while(!searchQueue.isEmpty()){
			Node currentNode = searchQueue.poll();
			
			for (int i=0; i<adjList.get(currentNode.nodeID).size(); i++){
				int targetNode = adjList.get(currentNode.nodeID).get(i);
				
				shortestPath.get(targetNode)
					.add(currentNode.nodeValue + matrix[currentNode.nodeID][targetNode]);
				
				Collections.sort(shortestPath.get(targetNode));
				
			}
			
			visited[currentNode.nodeID] = true;
		}
		Collections.sort(shortestPath.get(nodeCount - 1));
		
		System.out.println(shortestPath.get(nodeCount - 1).get(0));
		
	}
}
