import java.util.Scanner;

public class POJ_1258{

    /*
            CODE NOT WORKING, NEEDS DEBUG
     */

    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        int farmCount = keyboard.nextInt();

        if (farmCount == 0) System.exit(0);

        int[][] distance = new int[farmCount][farmCount];
        boolean[] visited = new boolean[farmCount];

        for (int i=0; i<farmCount; i++) {
            for (int j = 0; j < farmCount; j++) {
                distance[i][j] = keyboard.nextInt();
            }
        }

        int minimalDistance = 0;
        visited[0] = true;

        while(true){
            /*
                Check if all farms are visited
             */
            boolean allVisited = true;
            for (int i=0; i<visited.length; i++)
                if (!visited[i]) allVisited = false;

            if (allVisited) break;

            /*
                Find the shortest edge
             */

            int edgeLength = Integer.MAX_VALUE;
            int sourceNode = -1;
            int targetNode = -1;


            for (int i=0; i<visited.length; i++){
                if (visited[i]){
                    for (int j=0; j<visited.length; j++){
                        if (!visited[j] && i != j && distance[i][j] < edgeLength){
                            edgeLength = distance[i][j];
                            sourceNode = i;
                            targetNode = j;
                        }
                    }
                }
            }

            visited[targetNode] = true;
            visited[sourceNode] = true;
            minimalDistance += edgeLength;



        }

        System.out.print(minimalDistance);
    }
}
