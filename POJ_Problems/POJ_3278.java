import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class POJ_3278 {
	
	/*
	 * 		WARNING: This program is only semi-functional
	 */
	
	public static int farmerLocation;
	public static int cowLocation;
	
	public static int[] farm;
	public static boolean[] visited;
	
	public static Queue<Integer> currentLocation;
	public static Queue<Integer> currentSteps;
	
	public static void addData(int location, int steps){
		currentLocation.add(location);
		currentSteps.add(steps);
		return;
	}
	
	public static void search(){
		if (currentLocation.isEmpty()) return;
		
		int cLocation = currentLocation.poll();
		int cSteps = currentSteps.poll();
		
		if (visited[cLocation]) return;
		if (cLocation < 0 || cLocation >= 100001) return; 
		
		visited[cLocation] = true;
		
		if (farm[cLocation] != -1 && farm[cLocation] < cSteps) return;
		farm[cLocation] = cSteps;
		
		addData(cLocation + 1, cSteps + 1);
		addData(cLocation - 1, cSteps + 1);
		addData(cLocation * 2, cSteps + 1);
		
		return;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		currentLocation = new LinkedList<Integer>();
		currentSteps = new LinkedList<Integer>();
		
		farm = new int[100001];
		visited = new boolean[100001];
		
		for (int i=0; i<100001; i++) farm[i] = -1;
		
		farmerLocation = keyboard.nextInt();
		cowLocation = keyboard.nextInt();
		
		addData(farmerLocation, 0);
		
		while(!currentLocation.isEmpty()){
			search();
		}
		
		if (cowLocation >= 0 || cowLocation <= 100000){
			System.out.println(farm[cowLocation]);
		} else {
			System.out.println(0);
		}
		
	}
}
