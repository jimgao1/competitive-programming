import java.util.Scanner;

public class POJ_2328{
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        while(true){

            int maxNumber = Integer.MAX_VALUE;
            int minNumber = Integer.MIN_VALUE;

            boolean endGame = false;
            boolean endSubGame = false;

            while(!endSubGame){
                int currentNumber = keyboard.nextInt();

                if (currentNumber == 0) {
                    endGame = true;
                    break;
                }

                keyboard.nextLine();

                String comment = keyboard.nextLine();

                if (comment.equals("too high")){

                    if (currentNumber < maxNumber)
                        maxNumber = currentNumber;

                } else if (comment.equals("too low")){

                    if (currentNumber > minNumber)
                        minNumber = currentNumber;

                } else if (comment.equals("right on")){

                    if (currentNumber < maxNumber &&
                            currentNumber > minNumber){
                        System.out.println("Stan may be honest");

                    } else {

                        System.out.println("Stan is dishonest");
                    }

                    endSubGame = true;
                }


            }

            if (endGame) break;

        }
    }
}
