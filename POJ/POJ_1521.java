import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class POJ_1521 {

	public static class Node implements Comparable<Node>{
		public boolean isLeafNode;
		
		public int nodeWeight;
		public char nodeValue;
		
		public ArrayList<Node> child;
		
		public Node(){}
		
		public void initializeAsLeaf(int weight, char value){
			this.isLeafNode = true;
			this.nodeValue = value;
			this.nodeWeight = weight;
		}
		
		public void initializeAsParent(){
			this.isLeafNode = false;
			this.nodeValue = 0;
			child = new ArrayList<Node>();
		}

		public int compareTo(Node n) {
			return this.nodeWeight - n.nodeWeight;
		}
	}
	
	public static PriorityQueue<Node> rootNodes;
	public static String[] dictionary;
	
	public static void search(Node currentNode, String translation){
		if (currentNode.isLeafNode){
			dictionary[currentNode.nodeValue] = translation;
			return;
		}
		
		Node child1 = currentNode.child.get(0);
		Node child2 = currentNode.child.get(1);
		
		search(child1, translation + "0");
		search(child2, translation + "1");
		
		return;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		while(true){
			rootNodes = new PriorityQueue<Node>();
			
			String str = keyboard.nextLine();
			if (str.equals("END")) break;
			
			int[] letterOccurances = new int[127];
			dictionary = new String[127];
			
			for (int i=0; i<str.length(); i++){
				char currentLetter = str.charAt(i);
				letterOccurances[currentLetter - 1] += 1;
			}
			
			for (int i=0; i<127; i++){
				if (letterOccurances[i] != 0){
					Node n = new Node();
					n.initializeAsLeaf(letterOccurances[i], (char)(i + 1));
					rootNodes.add(n);
				}
			}
			
			while(rootNodes.size() > 1){
				Node n1 = rootNodes.poll();
				Node n2 = rootNodes.poll();
				
				Node parent = new Node();
				parent.initializeAsParent();
				
				parent.child.add(n1);
				parent.child.add(n2);
				parent.nodeWeight = n1.nodeWeight + n2.nodeWeight;
				
				rootNodes.add(parent);
			}
			
			search(rootNodes.peek(), "");
			
			int processedLength = 0;
			
			for (int i=0; i<str.length(); i++){
				if (dictionary[str.charAt(i)] != null)
					processedLength += dictionary[str.charAt(i)].length();
			}
			
			if (processedLength == 0){
				processedLength = str.length();
			}
			
			System.out.printf("%d %d %s\n", str.length() * 8, processedLength, new DecimalFormat("#.0").format((double)(str.length() * 8 ) / processedLength));
			
			
			
		}
		keyboard.close();
	}
}
