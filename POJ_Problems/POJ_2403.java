import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class POJ_2403{
    public static void main(String[] args){

        Scanner keyboard = new Scanner(System.in);

        int keyCount = keyboard.nextInt();
        int caseCount = keyboard.nextInt();

        Map<String, Integer> dictionary = new HashMap<String, Integer>();

        for (int i=0; i<keyCount; i++){
            String key = keyboard.next();
            int moneyValue = keyboard.nextInt();

            dictionary.put(key, moneyValue);
        }

        keyboard.nextLine();

        for (int i=0; i<caseCount; i++){
            int totalMoney = 0;

            while(true){
                String line = keyboard.nextLine();

                if (line.equals(".")) break;

                String[] words = line.split(" ");

                for (int j=0; j<words.length; j++){
                    if (dictionary.containsKey(words[j])){
                        totalMoney += dictionary.get(words[j]);
                    }
                }
            }

            System.out.println(totalMoney);
        }

    }
}
