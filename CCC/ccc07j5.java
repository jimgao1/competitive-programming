
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class ccc07j5 {
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
	
	public static int minDistance;
	public static int maxDistance;
	
	public static ArrayList<Integer> hotels;
	
	public static int ways;
	
	public static final int[] def = {
		0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000
	};
	
	public static boolean between(int a, int b, int c){
		return a <= b && b <= c;
	}
	
	public static void calc(int location){
		if (location >= 7000){
			ways += 1;
			return;
		}
		
		for (int i=1; i<hotels.size(); i++)
			if (between(minDistance, hotels.get(i) - location, maxDistance))
				calc(hotels.get(i));
	}
	
	public static void main(String[] args) {
		FastReader keyboard = new FastReader();
		
		ways = 0;
		hotels = new ArrayList<Integer>();
		
		for (int n : def) hotels.add(n);
		
		minDistance = keyboard.nextInt();
		maxDistance = keyboard.nextInt();
		
		int additional = keyboard.nextInt();
		while(additional-- != 0)
			hotels.add(keyboard.nextInt());
		
		Collections.sort(hotels);
		
		calc(1);
		
		System.out.println(ways);
	}
}
