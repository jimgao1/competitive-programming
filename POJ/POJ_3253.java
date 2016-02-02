import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class POJ_3253{
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        int planks = keyboard.nextInt();

        PriorityQueue<Integer> currentPlanks = new PriorityQueue<Integer>(10, Collections.reverseOrder());

        for (int i=0; i<planks; i++)
            currentPlanks.add(keyboard.nextInt());

        int currentPrice = 0;

        while(currentPlanks.size() > 1){

            int plank1 = currentPlanks.poll();
            int plank2 = currentPlanks.poll();


            currentPrice += plank1 + plank2;

            currentPlanks.add(plank1 + plank2);
        }

        System.out.println(currentPrice);
    }
}
