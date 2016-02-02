import java.util.Scanner;
import java.util.Arrays;

public class POJ_3069{
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        while(true){
            int r = keyboard.nextInt();
            int count = keyboard.nextInt();

            int[] positions = new int[count];

            for (int i=0; i<count; i++) positions[i] = keyboard.nextInt();

            Arrays.sort(positions);

            int currentPosition = 0;
            int minPoints = 0;

            while(currentPosition < count){
                int s = positions[currentPosition];
                currentPosition += 1;

                while(currentPosition < count && positions[currentPosition] <= s + r)
                    currentPosition += 1;

                int p = positions[currentPosition - 1];

                while(currentPosition < count && positions[currentPosition] <= p + r)
                    currentPosition += 1;

                minPoints += 1;
            }

            System.out.println(minPoints);
        }
    }
}
