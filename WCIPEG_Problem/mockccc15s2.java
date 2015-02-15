import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class mockccc15s2 {
	
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
		
		int contestCount = keyboard.nextInt();
		ArrayList<Integer> diff = new ArrayList<Integer>();
		
		for (int i=0; i<contestCount; i++)
			diff.add(keyboard.nextInt());
		
		Collections.sort(diff, Collections.reverseOrder());
		
		int lastType = diff.get(0);
		long maxLength = 1;
		long counter = 1;
		
		diff.remove(0);
		
		for (int n : diff){
			if (n == lastType){
				counter += 1;
			} else {
				maxLength = Math.max(maxLength, counter);
				counter = 1;
				lastType = n;
			}
		
		}
		maxLength = Math.max(maxLength, counter);
		
		System.out.println(maxLength);
	}
}
