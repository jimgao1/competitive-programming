import java.util.Scanner;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;
import java.util.Stack;

public class POJ_1463 {
	
	/*
	 * 		Formula:
	 * 
	 * 			f(i, 0) = sum of all child of node #i
	 * 			f(i, 1) = sum of min(f(j, 0), f(j, 1))
	 */
	
	
	public static boolean leafNode(Map<Integer, LinkedList<Integer>> adjList, int nodeCount, int node){
		if (node >= nodeCount) return false;
		if (adjList.get(node).isEmpty()) return true;
		return false;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		while(true){
			if (!keyboard.hasNextLine()) break;
			
			int nodeCount = keyboard.nextInt();
			keyboard.nextLine();
			
			Map<Integer, LinkedList<Integer>> adjList = new HashMap<Integer, LinkedList<Integer>>();
			int[] parent = new int[nodeCount];
			
			int rootNode = -1;
			
			for (int i=0; i<parent.length; i++) parent[i] = -1;
			
			
			for (int i=0; i<nodeCount; i++) adjList.put(i, new LinkedList<Integer>());
			
			for (int i=0; i<nodeCount; i++){
				String line = keyboard.nextLine();
				
				int currentNode = Integer.parseInt(line.split(":")[0]);
				String[] connectedString = line.split(" ");
				
				int connectedNodeCount = connectedString.length - 1;
				int[] connectedNodes = new int[connectedNodeCount];
				
				for (int j=0; j<connectedNodeCount; j++){
					connectedNodes[j] = Integer.parseInt(line.split(" ")[j + 1]);
				}
				
				for (int j=0; j<connectedNodeCount; j++){
					adjList.get(currentNode).add(connectedNodes[j]);
					parent[connectedNodes[j]] = currentNode;
				}
			}
			
			for (int i=0; i<adjList.size(); i++){
				if (parent[i] == -1) rootNode = i;
			}
			
			int[][] f = new int[nodeCount][2];
			
			boolean[] visited = new boolean[nodeCount];
			
			
			Stack<Integer> searchStack = new Stack<Integer>();
			searchStack.add(rootNode);
			
			while(true){
				if (searchStack.isEmpty()) break;
				
				int currentNode = searchStack.peek();
				
				if (leafNode(adjList, nodeCount, currentNode)){
					f[currentNode][1] = 1;
					f[currentNode][0] = 0;
					visited[currentNode] = true;
					searchStack.pop();
				} else {
					
					boolean childAllFucked = true;
					for (int i=0; i<adjList.get(currentNode).size(); i++){
						if (!visited[adjList.get(currentNode).get(i)]) childAllFucked = false;
					}
					
					if (childAllFucked){
						f[currentNode][0] = 0;
						f[currentNode][1] = 1;
						
						for (int i=0; i<adjList.get(currentNode).size(); i++){
							f[currentNode][0] += f[adjList.get(currentNode).get(i)][1];
							f[currentNode][1] += Math.min(f[adjList.get(currentNode).get(i)][0], 
									f[adjList.get(currentNode).get(i)][1]);
						}
						
						searchStack.pop();
						visited[currentNode] = true;
						continue;
					} else {
						for (int i=0; i<adjList.get(currentNode).size(); i++){
							if (!visited[adjList.get(currentNode).get(i)]) {
								searchStack.add(adjList.get(currentNode).get(i));
								continue;
							}
						}
					}
				
				}
			}
			
			System.out.println(Math.min(f[rootNode][0], f[rootNode][1]));
		}
	}
}
