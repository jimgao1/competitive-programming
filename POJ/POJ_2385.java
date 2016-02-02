import java.util.Scanner;

public class POJ_2385 {
	
	public static int totalTime;
	public static int totalMoves;
	
	public static int[] apple;
	
	public static int[][][] mem;
	
	public static int f(int time, int moves, int position){
		if (time == totalTime) return 0;
		
		if (mem[time][moves][position] != -1) return mem[time][moves][position];
		
		int current = 0;
		if (apple[time] == position) current = 1;
		
		if (moves >= totalMoves){
			mem[time][moves][position] = current + f(time + 1, moves, position);
			return mem[time][moves][position];
		} else {
			mem[time][moves][position] = current + Math.max(f(time + 1, moves, position),
								f(time + 1, moves + 1, 3 - position));
			return mem[time][moves][position];
		}
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		totalTime = keyboard.nextInt();
		totalMoves = keyboard.nextInt();
		
		apple = new int[totalTime];
		mem = new int[totalTime][totalMoves + 1][3];
		
		for (int i=0; i<totalTime; i++)
			for (int j=0; j<totalMoves + 1; j++)
				for (int k=0; k<3; k++)
					mem[i][j][k] = -1;
		
		for (int i=0; i<totalTime; i++)
			apple[i] = keyboard.nextInt();
		
		int result = Math.max(f(0, 0, 1), f(0, 0, 2));
		
		System.out.println(result);
	}
	
}
