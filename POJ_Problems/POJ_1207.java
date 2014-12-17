import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class POJ_1207{

    public static Map<Integer, Integer> pairs;

    public static int getCycle(int n){
        if (pairs.containsKey(n)) return pairs.get(n);

        int count = 0;

        while(n != 1){

            count += 1;

            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = n * 3 + 1;
            }
        }

        pairs.put(n, count + 1);

        return count + 1;
    }

    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        pairs = new HashMap<Integer, Integer>();

        while(keyboard.hasNext()){
            int startNumber = keyboard.nextInt();
            int endNumber = keyboard.nextInt();

            if (endNumber < startNumber){
                int temp = startNumber;
                startNumber = endNumber;
                endNumber = temp;
            }

            int maxCycle = 0;

            for (int i=startNumber; i<=endNumber; i++){
                int count = getCycle(i);

                if (count > maxCycle) maxCycle = count;
            }

            System.out.printf("%d %d %d\n", startNumber, endNumber, maxCycle);
        }
    }
}
