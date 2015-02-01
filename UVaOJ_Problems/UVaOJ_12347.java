import java.util.Scanner;
import java.util.ArrayList;

public class UVaOJ_12347 {
	
	public static class TreeNode{
		public int nodeValue;
		
		public TreeNode leftChild;
		public TreeNode rightChild;
		
		public TreeNode(){}
		public TreeNode(int value){
			this.nodeValue = value;
		}
	}
	
	public static TreeNode rootNode;
	
	public static void addNode(TreeNode current, int value){
		if (value < current.nodeValue){
			if (current.leftChild == null)
				current.leftChild = new TreeNode(value);
			else
				addNode(current.leftChild, value);
		} else {
			if (current.rightChild == null)
				current.rightChild = new TreeNode(value);
			else
				addNode(current.rightChild, value);
		}
	}
	
	public static ArrayList<Integer> postOrder(TreeNode current){
		if (current == null)
			return new ArrayList<Integer>();
		
		ArrayList<Integer> result = new ArrayList<Integer>();
		result.addAll(postOrder(current.leftChild));
		result.addAll(postOrder(current.rightChild));
		result.add(current.nodeValue);
		
		return result;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		rootNode = new TreeNode(keyboard.nextInt());
		
		while(keyboard.hasNext()){
			int nodeValue = keyboard.nextInt();
			
			addNode(rootNode, nodeValue);
		}
		
		ArrayList<Integer> result = postOrder(rootNode);
		
		for (int n : result)
			System.out.println(n);
	}
}
