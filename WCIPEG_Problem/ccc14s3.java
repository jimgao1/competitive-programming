/**
 * Created by Jim on 2/8/2015.
 */

import java.util.Scanner;
import java.util.Stack;

public class ccc14s3 {

    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        int caseCount = keyboard.nextInt();

        while(caseCount-- != 0){
            Stack<Integer> mountainTop = new Stack<Integer>();
            Stack<Integer> branch = new Stack<Integer>();

            int cartCount = keyboard.nextInt();

            for (int i=0; i<cartCount; i++)
                mountainTop.add(keyboard.nextInt());

            int currentNumber = 1;

            boolean noSolution = true;

            while(true){
                if (mountainTop.isEmpty() && branch.isEmpty()) {
                    noSolution = false;
                    break;
                }

                /*
                    Check if mountainTop has the current number
                 */

                if (!mountainTop.isEmpty() && mountainTop.peek() == currentNumber){
                    mountainTop.pop();
                    currentNumber += 1;
                    continue;
                } else if (!branch.isEmpty() && branch.peek() == currentNumber){
                    branch.pop();
                    currentNumber += 1;
                    continue;
                } else {
                    if (mountainTop.isEmpty()){
                        break;
                    }

                    branch.push(mountainTop.pop());
                }

            }

            if (noSolution)
                System.out.println("N");
            else
                System.out.println("Y");
        }
    }

}
