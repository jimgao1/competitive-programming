import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class graph3p2{
	
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
	public static void main(String[] args) throws NumberFormatException, IOException{
		
		FastScanner scanner = new FastScanner();
		
		int nodeCount = scanner.nextInt();
		int edgeCount = scanner.nextInt();
		
		int[][] matrix = new int[nodeCount][nodeCount];
		
		for (int i=0; i<edgeCount; i++){
			int nodeA = scanner.nextInt() - 1;
			int nodeB = scanner.nextInt() - 1;
			int dist = scanner.nextInt();
			
			matrix[nodeA][nodeB] = dist;
		
		}
		
		int[] distance = new int[nodeCount];
		for (int i=0; i<nodeCount; i++)
			distance[i] = 1000000000;
		
		distance[0] = 0;
		
		Queue<Integer> spfa = new LinkedList<Integer>();
		spfa.add(0);
		
		boolean[] qContains = new boolean[nodeCount];
		qContains[0] = true;
		
		while(!spfa.isEmpty()){
			int currentNode = spfa.remove();
			qContains[currentNode] = false;
			
			for (int i=0; i<nodeCount; i++){
				if (matrix[currentNode][i] != 0){
					if (distance[i] > distance[currentNode] + matrix[currentNode][i]){
						distance[i] = distance[currentNode] + matrix[currentNode][i];
						
						if (!qContains[i]){
							qContains[i] = true;
							spfa.add(i);
						}
					}
					
				}
			}
		}
		
		System.out.println(distance[nodeCount - 1]);
	}
}
