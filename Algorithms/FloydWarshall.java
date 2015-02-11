
public class FloydWarshall{
  public static int[][] floydWarshall(int[][] matrix){
		int nodeCount = matrix.length;		
		int[][] distance = new int[nodeCount][nodeCount];
		
		for (int i=0; i<nodeCount; i++)
			distance[i][i] = 0;
		
		for (int i=0; i<nodeCount; i++)
			for (int j=0; j<nodeCount; j++)
				if (matrix[i][j] != -1)
					distance[i][j] = matrix[i][j];
		
		for (int k=0; k<nodeCount; k++)
			for (int i=0; i<nodeCount; i++)
				for (int j=0; j<nodeCount; j++)
					if (distance[i][j] > distance[i][k] + distance[k][j])
						distance[i][j] = distance[i][k] + distance[k][j];
		
		return distance;
		
	}
	
}
