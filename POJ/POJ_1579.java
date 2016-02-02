import java.util.Scanner;

public class POJ_1579 {
	
	public static long[][][] w;
	
	public static long f(int a, int b, int c){
		
		//System.out.printf("f(%d, %d, %d);\n", a, b, c);
		
		if (a > 20 || b > 20 || c > 20) return f(20, 20, 20);
		if (a <= 0 || b <= 0 || c <= 0) return 1;
		
		long answer = w[a][b][c];
		
		if (answer != -1) return answer;
		
		if (a < b && b < c){
			answer = f(a, b, c-1) + f(a, b-1, c-1) - f(a, b-1, c);
			w[a][b][c] = answer;
			return answer;
		}
		
		answer = f(a-1, b, c) + f(a-1, b-1, c) + f(a-1, b, c-1) - f(a-1, b-1, c-1);
		w[a][b][c] = answer;
		
		return answer;
	}
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		w = new long[21][21][21];
		
		for (int i=0; i<21; i++){
			for (int j=0; j<21; j++){
				for (int k=0; k<21; k++){
					w[i][j][k] = -1;
				}
			}
		}
		
		while(true){
			int a = keyboard.nextInt();
			int b = keyboard.nextInt();
			int c = keyboard.nextInt();
			
			if (a == -1 && b == -1 && c == -1) break;
			
			System.out.printf("w(%d, %d, %d) = %d\n", a, b, c, f(a, b, c));
		}
		
		keyboard.close();
	}
}
