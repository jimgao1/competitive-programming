import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class ccc13s4 {
	
	public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            try {
                br = new BufferedReader(new InputStreamReader(System.in));
            } catch (Exception ex){}
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
	}
	
	public static ArrayList<ArrayList<Integer>> adjList;
	
	public static boolean taller(int pA, int pB){
		Queue<Integer> bfs = new LinkedList<Integer>();
		boolean[] visited = new boolean[adjList.size()];
		
		for (int i=0; i<adjList.get(pA).size(); i++)
			bfs.add(adjList.get(pA).get(i));
		
		while(!bfs.isEmpty()){
			int n = bfs.poll();
			
			if (n == pB) return true;
			if (!visited[n]){
				visited[n] = true;
				for (int x : adjList.get(n))
					bfs.add(x);
			}
		}
		
		return false;
	}
	
	public static void main(String[] args){
		FastScanner keyboard = new FastScanner();
		
		int peopleCount = keyboard.nextInt();
		int comparasonCount = keyboard.nextInt();
		
		/*
		 * 		adjList.get(i):
		 * 			everything that is shorter than i
		 */
		adjList = new ArrayList<ArrayList<Integer>>();
		
		for (int i=0; i<peopleCount; i++)
			adjList.add(i, new ArrayList<Integer>());
		
		for (int i=0; i<comparasonCount; i++){
			int personA = keyboard.nextInt() - 1;
			int personB = keyboard.nextInt() - 1;
			
			adjList.get(personA).add(personB);
		}
		
		int pA = keyboard.nextInt() - 1;
		int pB = keyboard.nextInt() - 1;
		
		if (taller(pA, pB))
			System.out.println("yes");
		else if (taller(pB, pA))
			System.out.println("no");
		else
			System.out.println("unknown");
	}
}
