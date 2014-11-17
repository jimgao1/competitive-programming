/*
 * 		Problem URL: 
 * 			http://interactivepython.org/runestone/static/pythonds/Graphs/graphdfs.html
 * 
 */

import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;

public class Knight_Move_Problem {

	public static boolean[][] visited;
	public static int xSize;
	public static int ySize;
	public static int positionCount;
	
	public static Queue<Integer> xPos;
	public static Queue<Integer> yPos;
	public static Queue<Integer> level;
	
	public static ArrayList<Integer> xHistory;
	public static ArrayList<Integer> yHistory;
	public static ArrayList<Integer> levelHistory;
	
	public static void addPoint(int x, int y, int l){
		xPos.add(x);
		yPos.add(y);
		level.add(l);
		return;
	}
	
	public static void bfs(){
		
		int xPosition = xPos.poll();
		int yPosition = yPos.poll();
		int currentLevel = level.poll();
		
		if (xPosition < 0 || xPosition >= xSize) return;
		if (yPosition < 0 || yPosition >= ySize) return;
		
		if (visited[xPosition][yPosition]) return;
		positionCount += 1;
		
		visited[xPosition][yPosition] = true;
		
		xHistory.add(xPosition);
		yHistory.add(yPosition);
		levelHistory.add(currentLevel);
		
		
		
		addPoint(xPosition + 1, yPosition - 2, currentLevel + 1);
		addPoint(xPosition - 1, yPosition - 2, currentLevel + 1);
		addPoint(xPosition + 2, yPosition - 1, currentLevel + 1);
		addPoint(xPosition + 2, yPosition + 1, currentLevel + 1);
		addPoint(xPosition + 1, yPosition + 2, currentLevel + 1);
		addPoint(xPosition - 1, yPosition + 2, currentLevel + 1);
		addPoint(xPosition - 2, yPosition - 1, currentLevel + 1);
		addPoint(xPosition - 2, yPosition + 1, currentLevel + 1);
		
		return;
		
	}
	
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		xSize = keyboard.nextInt();
		ySize = keyboard.nextInt();
		int xPosition = keyboard.nextInt();
		int yPosition = keyboard.nextInt();
		
		visited = new boolean[xSize][ySize];
		positionCount = 0;
		
		xPos = new LinkedList<Integer>();
		yPos = new LinkedList<Integer>();
		level = new LinkedList<Integer>();
		
		xHistory = new ArrayList<Integer>();
		yHistory = new ArrayList<Integer>();
		levelHistory = new ArrayList<Integer>();
		
		xPos.add(xPosition);
		yPos.add(yPosition);
		level.add(0);
		
		while(!xPos.isEmpty()){
			bfs();
		}

		for (int i=0; i<xHistory.size(); i++){
			System.out.printf("x: %d\ty: %d\tlevel: %d\n", xHistory.get(i), yHistory.get(i), levelHistory.get(i));
		}
		
		
	}

}
