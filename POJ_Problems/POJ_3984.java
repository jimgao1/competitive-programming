import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;


public class POJ_3984 {
	
	
	public static class SearchState{
		
		public int locationX;
		public int locationY;
		
		public LinkedList<Integer> historyX;
		public LinkedList<Integer> historyY;
		
		public boolean[][] visited;
		
		public SearchState(){}
		public SearchState(SearchState s){
			this.locationX = s.locationX;
			this.locationY = s.locationY;
			this.historyX = (LinkedList<Integer>) s.historyX.clone();
			this.historyY = (LinkedList<Integer>) s.historyY.clone();
			this.visited = (boolean[][]) s.visited.clone();
		}
		
	}

	public static final int[][] moves = {
		{0, 1}, {0, -1}, {1, 0}, {-1, 0}
	};
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		int[][] maze = new int[5][5];
		
		for (int i=0; i<5; i++)
			for (int j=0; j<5; j++)
				maze[j][i] = keyboard.nextInt();
		
		SearchState initial = new SearchState();
		initial.locationX = 0;
		initial.locationY = 0;
		initial.historyX = new LinkedList<Integer>();
		initial.historyY = new LinkedList<Integer>();
		initial.historyX.add(0);
		initial.historyY.add(0);
		initial.visited = new boolean[5][5];
		
		Queue<SearchState> searchQueue = new LinkedList<SearchState>();
		searchQueue.add(initial);
		
		while(!searchQueue.isEmpty()){
			SearchState currentState = searchQueue.poll();
			
			if (currentState.locationX < 0 || currentState.locationX >= 5) continue;
			if (currentState.locationY < 0 || currentState.locationY >= 5) continue;
			
			if (currentState.visited[currentState.locationX][currentState.locationY]) continue;
			currentState.visited[currentState.locationX][currentState.locationY] = true;
			
			if (maze[currentState.locationX][currentState.locationY] == 1) continue;
			
			if (currentState.locationX == 4 && currentState.locationY == 4){
				for (int i=0; i<currentState.historyX.size(); i++){
					System.out.printf("(%d, %d)\n", currentState.historyY.get(i), currentState.historyX.get(i));
				}
				break;
			}
			
			for (int i=0; i<4; i++){
				SearchState newState = new SearchState(currentState);
				newState.locationX = currentState.locationX + moves[i][0];
				newState.locationY = currentState.locationY + moves[i][1];
				newState.historyX.add(newState.locationX);
				newState.historyY.add(newState.locationY);
				
				searchQueue.add(newState);
			}
		}
		
	}
}
