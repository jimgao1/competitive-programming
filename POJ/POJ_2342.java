import java.util.Scanner;
import java.util.Stack;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;

public class POJ_2342 {

	/*
	 * 		f[i, 1] = sum of all f[j, 0]
	 * 			where j is all kids of i
	 * 
	 * 		f[i, 0] = sum of all max(f[j, 0] and f[j, 1])
	 * 			where j is all kids of i
	 * 		
	 * 		since all the kids of a node does NOT affect 
	 * 		each other
	 * 
	 * 
	 * 		since the upper node determines the values of
	 * 		the children nodes
	 * 
	 * 		
	 * 		the base case is the nodes who does not have
	 * 		any kids (lol), since they are the easiest to
	 * 		compute.
	 */
	
	public static int[] priority;
	public static int[] tree;
	public static int[][] f;
	
	public static Map<Integer, LinkedList<Integer>> slaves;
	public static Stack<Integer> dfs;
	
	public static int max(int a, int b){
		if (b > a) return b;
		return a;
	}
	
	public static int max(int[] array){
		int max = Integer.MIN_VALUE;
		
		for (int i=0; i<array.length; i++){
			if (array[i] > max) max = array[i];
		}
		
		return max;
	}
	
	public static void dfs(int currentNode){
		if (slaves.get(currentNode).size() == 0){
			f[currentNode][0] = priority[currentNode];
			f[currentNode][1] = priority[currentNode];
			
			dfs.pop();
			return;
		}
		
		for (int i=0; i<slaves.get(i).size(); i++){
			dfs.add(slaves.get(i).get(i));
			dfs(slaves.get(currentNode).get(i));
		}
		
		f[currentNode][1] = priority[currentNode];
		
		int sum = 0;
		
		for (int i=0; i<slaves.get(currentNode).size(); i++){
			sum += max(f[slaves.get(currentNode).get(i)][1], 
					f[slaves.get(currentNode).get(i)][0]);
		}
		
		dfs.pop();
		return;
	}
	
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		/*
		 * 		Input the number of nodes
		 * 		and
		 * 		Initialize the variables
		 */
		
		int nodeCount = keyboard.nextInt();
		priority = new int[nodeCount];
		tree = new int[nodeCount];
		f = new int[nodeCount][2];
		
		slaves = new HashMap<Integer, LinkedList<Integer>>();
		dfs = new Stack<Integer>();

		
		/*
		 * 		Input all the priorities 
		 * 		of the nodes
		 */
		
		for (int i=0; i<nodeCount; i++) {
			priority[i] = keyboard.nextInt();
			f[i][1] = priority[i];
		}
		for (int i=0; i<nodeCount; i++) tree[i] = -1;
		for (int i=0; i<nodeCount; i++) slaves.put(i, new LinkedList<Integer>());
		
		/*
		 * 		Enter the boss/slave relationships
		 */
		
		while(true){
			int slave = keyboard.nextInt();
			int boss = keyboard.nextInt();
			
			if (slave == 0 && boss == 0) break;
			
			tree[slave] = boss;
			slaves.get(boss).add(slave);
		}
		
		ArrayList<Integer> bosses = new ArrayList<Integer>();
		
		for (int i=0; i<nodeCount; i++){
			if (tree[i] == -1) bosses.add(i);
		}
		
		for (int i=0; i<bosses.size(); i++){
			dfs.add(bosses.get(i));
			dfs(bosses.get(i));
		}
		
		int finalSum = 0;
		
		for (int i=0; i<bosses.size(); i++){
			finalSum += max(f[bosses.get(i)][0], f[bosses.get(i)][1]);
		}
		
		System.out.println(finalSum);
		
	}
}
