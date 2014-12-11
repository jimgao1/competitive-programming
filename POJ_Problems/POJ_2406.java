import java.util.Scanner;

public class POJ_2406{

    public static boolean isRootString(String str, String root){

        while(true) {
            if (str.length() == 0) return true;

            if (str.length() % root.length() != 0) return false;
            if (str.length() < root.length()) return false;

            for (int i=0; i<root.length(); i++){
                if (root.charAt(i) != str.charAt(i)) return false;
            }

            str = str.substring(root.length());
        }
    }

    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        while(true){
            String s = keyboard.next();

            if (s.equals(".")) break;

            for (int i=1; i<s.length() + 1; i++){
                if (isRootString(s, s.substring(0, i))){
                    System.out.println(s.length() / i);
                    break;
                }
            }
        }
    }
}
