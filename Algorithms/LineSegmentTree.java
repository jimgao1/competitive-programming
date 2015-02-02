
import java.util.Scanner;

public class LineSegmentTree{
	
	public static class LSTNode{
		public int nodeValue;
		
		public int nStart;
		public int nEnd;
		
		public LSTNode(){}
		public LSTNode(int s, int e){
			this.nStart = s;
			this.nEnd = e;
		}
		public LSTNode(int val, int s, int e){
			this.nodeValue = val;
			this.nStart = s;
			this.nEnd = e;
		}
	}
	
	/*
	 * 		Array for Line Segment Tree
	 * 
	 * 		segmentTree[0]: the ROOT node
	 * 		
	 * 		For segmentTree[i]:
	 * 			leftChild: 		segmentTree[2 * i + 1]
	 * 			rightChild: 	segmentTree[2 * i + 2]
	 */
	public static LSTNode[] segmentTree;
	
	/*
	 * 		The node value for the leaf nodes, or
	 * 		the independent nodes. 
	 */
	public static int[] leafValue;
	
	public static void buildTree(int current, int startIndex, int endIndex){
		if (startIndex == endIndex){ 	//If current node is leaf
			segmentTree[current] = new LSTNode(leafValue[startIndex], startIndex, endIndex);
		} else {
			segmentTree[current] = new LSTNode(startIndex, endIndex);
			
			int mid = (startIndex + endIndex) / 2;
			
			/*
			 * 		Build the tree recursively, first the left child,
			 * 		and then the right one. 
			 */
			buildTree(current * 2 + 1, startIndex, mid);
			buildTree(current * 2 + 2, mid + 1, endIndex);
			
			segmentTree[current].nodeValue = 
					segmentTree[current * 2 + 1].nodeValue + segmentTree[current * 2 + 2].nodeValue;
		}
	}
	
	
	/*
	 * 		Query the sum from qStart to qEnd
	 * 
	 * 		current node is the current root node
	 */
	public static int querySum(int current, int qStart, int qEnd){
		int nStart = segmentTree[current].nStart;
		int nEnd = segmentTree[current].nEnd;
		
		//System.out.printf("[QUERY] id: %d, node = [%d, %d], query = [%d, %d]  [RESULT 0]\n", current, nStart, nEnd, qStart, qEnd);
		
		if (qStart > nEnd || qEnd < nStart){
			//System.out.printf("[QUERY] id: %d, node = [%d, %d], query = [%d, %d]  [RESULT 0]\n", current, nStart, nEnd, qStart, qEnd);
			return 0;
		}
		
		if (qStart <= nStart && qEnd >= nEnd){
			//System.out.printf("[QUERY] id: %d, node = [%d, %d], query = [%d, %d]  [RESULT %d]\n", current, nStart, nEnd, qStart, qEnd, segmentTree[current].nodeValue);
			return segmentTree[current].nodeValue;
		}
		
		
		
		int mid = (nStart + nEnd) / 2;
		
		int result = querySum(current * 2 + 1, qStart, qEnd) + 
				querySum(current * 2 + 2, qStart, qEnd);
		
		//System.out.printf("[QUERY] id: %d, node = [%d, %d], query = [%d, %d]  [RESULT %d]\n", current, nStart, nEnd, qStart, qEnd, result);
		
		return result;
	}
	
	public static void updateNode(int current, int index, int diff){
		int nStart = segmentTree[current].nStart;
		int nEnd = segmentTree[current].nEnd;
		
		if (nStart == nEnd){
			if (index == nStart)
				segmentTree[current].nodeValue += diff;
			
			return;
		}
		
		int mid = (nStart + nEnd) / 2;
		
		if (index <= mid)
			updateNode(current * 2 + 1, index, diff);
		else 
			updateNode(current * 2 + 2, index, diff);
		
		segmentTree[current].nodeValue = 
				segmentTree[current * 2 + 1].nodeValue + segmentTree[current * 2 + 2].nodeValue;
	}
	
	public static void printLST(){
		for (int i=0; i<segmentTree.length; i++){
			System.out.printf("%d\t", i);
			
			if (segmentTree[i] == null){
				System.out.println("NULL");
			} else {
				System.out.println(segmentTree[i].nodeValue);
				System.out.println("\t" + segmentTree[i].nStart + "\t" + segmentTree[i].nEnd);
			}
		}
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int nodeCount = keyboard.nextInt();
		
		leafValue = new int[nodeCount];
		
		for (int i=0; i<nodeCount; i++)
			leafValue[i] = keyboard.nextInt();
		
		segmentTree = new LSTNode[nodeCount * 2 + 4];
		
		buildTree(0, 0, nodeCount - 1);
		
		printLST();
		
		while(keyboard.hasNext()){
			int index = keyboard.nextInt();
			int diff = keyboard.nextInt();
			
			updateNode(0, index, diff);
			
			printLST();
		}
	}
}