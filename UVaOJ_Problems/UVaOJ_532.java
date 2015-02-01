import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class UVaOJ_532 {
	
	public static int[] gridSize;
	public static int[] start;
	public static int[] finish;
	
	public static char[][][] grid;
	
	/*
	 * 		Possible Moves:
	 * 			x + 1, y, z
	 * 			x - 1, y, z
	 * 			x, y + 1, z
	 * 			x, y - 1, z
	 * 			x, y, z + 1
	 * 			x, y, z - 1
	 */
	
	public static final int[][] moves = {
		{1, 0, 0}, {-1, 0, 0}, 
		{0, 1, 0}, {0, -1, 0},
		{0, 0, 1}, {0, 0, -1}
	};
	
	public static class SearchState{
		public int[] location;
		public boolean[][][] visited;
		public int steps;
		
		public SearchState(){}
		
		public SearchState(SearchState n){
			this.location = (int[])n.location.clone();
			this.visited = (boolean[][][])n.visited.clone();
			this.steps = n.steps;
		}
		
		public void initialize(){
			visited = new boolean[gridSize[0]][gridSize[1]][gridSize[2]];
		}
	}
	
	public static boolean validState(SearchState state){
		if (state.location[0] < 0 || state.location[0] >= gridSize[0]) return false;
		if (state.location[1] < 0 || state.location[1] >= gridSize[1]) return false;
		if (state.location[2] < 0 || state.location[2] >= gridSize[2]) return false;
		
		if (state.visited[state.location[0]][state.location[1]][state.location[2]])
			return false;
		
		if (grid[state.location[0]][state.location[1]][state.location[2]] == '#') return false;
		
		return true;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		while(true){
			int sizeZ = keyboard.nextInt();
			int sizeY = keyboard.nextInt();
			int sizeX = keyboard.nextInt();
			
			if (sizeX == 0 && sizeY == 0 && sizeZ == 0) break;
			
			keyboard.nextLine();
			
			gridSize = new int[]{sizeX, sizeY, sizeZ};
			grid = new char[sizeX][sizeY][sizeZ];
			
			for (int currentZ = 0; currentZ < sizeZ; currentZ += 1){
				for (int currentY = 0; currentY < sizeY; currentY += 1){
					String line = keyboard.nextLine();
					for (int currentX = 0; currentX < sizeX; currentX += 1){
						grid[currentX][currentY][currentZ] = line.charAt(currentX);
						
						if (grid[currentX][currentY][currentZ] == 'S')
							start = new int[]{currentX, currentY, currentZ};
						
						if (grid[currentX][currentY][currentZ] == 'E')
							finish = new int[]{currentX, currentY, currentZ};
					}
				}
				keyboard.nextLine();
			}
			
			SearchState initial = new SearchState();
			initial.initialize();
			initial.location = new int[]{start[0], start[1], start[2]};
			initial.steps = 0;
			
			Queue<SearchState> searchQueue = new LinkedList<SearchState>();
			searchQueue.add(initial);
			
			boolean pathFound = false;
			
			while(!searchQueue.isEmpty()){
				SearchState currentState = searchQueue.poll();
				
				if (!validState(currentState)) continue;
				currentState.
				visited[currentState.location[0]]
						[currentState.location[1]]
								[currentState.location[2]] = true;
				
				if (grid[currentState.location[0]]
						[currentState.location[1]]
								[currentState.location[2]] == 'E'){
					System.out.printf("Escaped in %d minute(s).\n", currentState.steps);
					pathFound = true;
					break;
				}
				
				for (int i=0; i<6; i++){
					SearchState nextStep = new SearchState(currentState);
					nextStep.location[0] += moves[i][0];
					nextStep.location[1] += moves[i][1];
					nextStep.location[2] += moves[i][2];
					nextStep.steps += 1;
					
					searchQueue.add(nextStep);
				}
			}
			
			if (!pathFound)
				System.out.println("Trapped!");
				
			
		}
	}
}
