import java.util.Scanner;

public class POJ_3673{
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        String numberA = keyboard.next();
        String numberB = keyboard.next();

        int sum = 0;

        for (int i=0; i<numberA.length(); i++){
            for (int j=0; j<numberB.length(); j++){
                sum += (int)(numberA.charAt(i) - '0') * (int)(numberB.charAt(j) - '0');
            }
        }

        System.out.println(sum);
    }
}
