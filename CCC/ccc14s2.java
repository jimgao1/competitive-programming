import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class ccc14s2 {
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
	
	public static void goToHell(){
		System.out.println("bad");
		System.exit(0);
	}
	
	public static void main(String[] args) {
		FastReader keyboard = new FastReader();
		
		int pairCount = keyboard.nextInt();
		
		ArrayList<String> personA = new ArrayList<String>();
		ArrayList<String> personB = new ArrayList<String>();
		
		for (int i=0; i<pairCount; i++)
			personA.add(keyboard.nextToken());
		
		for (int i=0; i<pairCount; i++)
			personB.add(keyboard.nextToken());
		
		/*
		 * 		Fail Conditions:
		 * 			1. Person trying to pair with himself
		 * 			2. Person A trying to pair with Person B, but B is not pairing with A
		 * 
		 * 		Technically if test case satisfies 1 and 2, it should work :D
		 */
		
		/*
		 * 		Check case 1
		 */
		
		for (int i=0; i<pairCount; i++)
			if (personA.get(i).equals(personB.get(i))) {
				goToHell();
			}
		
		/*
		 * 		Check Case 3
		 */
		
		
		for (int i=0; i<pairCount; i++){
			String pA = personA.get(i);
			String pB = personB.get(i);
			
			if (!personB.get(personA.indexOf(pB)).equals(pA)) goToHell();
		}
		
		System.out.println("good");
	}
}
