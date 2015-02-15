import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class mockccc15s1 {
	
	public static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException ex) {
					ex.printStackTrace();
				}
			}

			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		public String nextLine() { 
			try {
				return br.readLine();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
			return null;
		}
	}
	
	public static void main(String[] args){
		FastReader keyboard = new FastReader();
		
		int netPoints = keyboard.nextInt();
		int totalUsers = keyboard.nextInt();
		
		int r1 = keyboard.nextInt();
		int r2 = keyboard.nextInt();
		
		double ratio = (double)(r1) / r2;
		
		int count = 0;
		
		for(int i=0; i<1001; i++){
			for (int j=0; j<1001; j++){
				double x3 = totalUsers - i - j;
				if (x3 >= 0){
					if (2*i + j - x3 == netPoints){
						double x1 = i;
						double x2 = j;
						
						if (x1 / x2 == ratio ||
								x2 / x1 == ratio ||
								x1 / x3 == ratio ||
								x3 / x1 == ratio ||
								x2 / x3 == ratio ||
								x3 / x2 == ratio) count += 1;
					}
				}
			}
		}
		
		System.out.println(count);
	}
}
