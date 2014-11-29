import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;

public class Box_Stacking {
	
	/*
	 * 			HI THERE
	 * 		Problem:
	 * 			I have n boxes, and each of them has 3 dimensions.
	 * 
	 * 
	 * 			I want to stack them so that the upper block has a smaller
	 * 			base than the lower one, and I want to know what is the 
	 * 			biggest possible height of that stack.
	 * 
	 */
	
	public static class Box implements Comparable{
		public int height;
		public int width;
		public int depth;
		
		public Box(int a, int b, int c){
			this.height = a;
			this.width = b;
			this.depth = c;
		}
		
		public Box cloneBox(){
			Box x = new Box(height, width, depth);
			return x;
		}
		
		public int getBaseArea(){
			return width * depth;
		}

		@Override
		public int compareTo(Object arg0) {
			Box n = (Box)arg0;
			return height - n.height;
		}
		
	}
	
	public static int random(){
		return (int)(Math.random() * 40) + 1;
	}
	
	public static ArrayList<Box> boxes;
	public static int[] f;
	
	public static void main(String[] args){
		
		Scanner keyboard = new Scanner(System.in);
		
		boxes = new ArrayList<Box>();
			
		int boxCount = keyboard.nextInt();
		f = new int[boxCount];	
		for (int i=0; i<boxCount; i++){
			boxes.add(new Box(random(), random(), random()));
		}
		
		Collections.sort(boxes);
		
		for (int i=0; i<boxCount; i++){
			int maxValue = boxes.get(i).height;
			
			for (int j=0; j<i; j++){
				if (f[j] > maxValue){
					maxValue = f[j];
				}
			}
			
			f[i] = maxValue;
		}
		
		System.out.println(f[boxCount - 1]);
		
	}
}
