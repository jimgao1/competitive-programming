import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class ccc14s1 {
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
	
	public static void main(String[] args) {
		FastReader keyboard = new FastReader();
		
		int friendCount = keyboard.nextInt();
		int roundCount = keyboard.nextInt();
		
		int[] rounds = new int[roundCount];
		for (int i=0; i<roundCount; i++)
			rounds[i] = keyboard.nextInt();
		
		ArrayList<Integer> friends = new ArrayList<Integer>();
		
		for (int i=0; i<friendCount; i++)
			friends.add(i + 1);
		
		for (int i=0; i<roundCount; i++){
			ArrayList<Integer> removePending = new ArrayList<Integer>();
			for (int j=0; j<friends.size(); j++)
				if ((j + 1) % rounds[i] == 0)
					removePending.add(friends.get(j));
			
			for (int remove : removePending)
				friends.remove(friends.indexOf(remove));
		}
		
		for (int n : friends)
			System.out.println(n);
	}
}
