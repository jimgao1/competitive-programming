import java.util.Scanner;

public class POJ_2342_New{

    public static int peopleCount;
    public static int rootID;

    public static int[] empRating;
    public static int[] empBoss;
    public static boolean[] visited;

    public static int[][] dp;

    public static void search(int currentNode){
        if (visited[currentNode]) return;

        for (int i=0; i<peopleCount; i++){
            if (!visited[i] && empBoss[i] == currentNode){
                search(i);
            }
        }

        dp[currentNode][0] = 0;
        for (int i=0; i<peopleCount; i++){
            if (empBoss[i] == currentNode){
                dp[currentNode][0] += Math.max(dp[i][0], dp[i][1]);
            }
        }

        dp[currentNode][1] = empRating[currentNode];
        for (int i=0; i<peopleCount; i++){
            if (empBoss[i] == currentNode){
                dp[currentNode][1] += dp[i][0];
            }
        }
    }

    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        peopleCount = keyboard.nextInt();

        empRating = new int[peopleCount];
        empBoss = new int[peopleCount];
        visited = new boolean[peopleCount];

        dp = new int[peopleCount][2];


        /*
            Input the empRating
         */

        for (int i=0; i<peopleCount; i++) {
            empRating[i] = keyboard.nextInt();
            empBoss[i] = -1;
        }

        while(true){
            int slaveID = keyboard.nextInt() - 1;
            int bossID = keyboard.nextInt() - 1;

            if (slaveID == -1 && bossID == -1) break;

            empBoss[slaveID] = bossID;
        }

        for (int i=0; i<peopleCount; i++)
            if (empBoss[i] == -1) rootID = i;


        search(rootID);

        System.out.println(Math.max(dp[rootID][0], dp[rootID][1]));
    }
}
