import java.util.Scanner;

public class ccc97s2{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for (int i = 0; i < T; i++){
			int N = sc.nextInt();
			
			boolean nasty = false;
			for (int j = 1; j <= N; j++){
				if (N % j == 0){
					for (int k = 1; k <= N; k++){
						if (N % k == 0){
							if ((N / k) - k == (N / j) + j){
								nasty = true;
							}
						}
					}
				}
			}
			
			if (nasty){
				System.out.printf("%d is nasty\n", N);
			} else {
				System.out.printf("%d is not nasty\n", N);
			}
			
		}
	}
}

