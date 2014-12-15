import java.util.Scanner;

public class Non_Decreasing_Subsequence{

    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        int numberCount = keyboard.nextInt();

        int[] numbers = new int[numberCount];
        int[] f = new int[numberCount];

        for (int i=0; i<numberCount; i++) {
            numbers[i] = keyboard.nextInt();
        }


        int maxLength = 0;

        for (int i=0; i<numberCount; i++){
            f[i] = 1;
            for (int j=0; j<i; j++){
                if (numbers[j] < numbers[i])
                    f[i] = Math.max(f[i], f[j] + 1);
            }
            maxLength = Math.max(maxLength, f[i]);
        }

        System.out.println(f[numberCount - 1]);
    }
}
