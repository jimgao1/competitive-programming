import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class ccc98s4 {

    public static String proc(String str, boolean times){
        ArrayList<String> signs = new ArrayList<>();
        for (char c : str.toCharArray()){
            if (c == '+' || c == '-')
                signs.add(Character.toString(c));
        }
        String result = "";
        String[] tokens = str.split(times ? "X" : "[+-]");
        for (int i = 0; i < tokens.length - 1; i++){
            result += "(";
        }
        result += tokens[0];
        int cnt = 0;
        for (int i = 1; i < tokens.length; i++) {
            result += String.format(" %s %s)", times ? "X" : signs.get(cnt++), tokens[i]);
        }
        return result;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());

        while(N-- != 0){
            String exp = sc.nextLine();

            exp = exp.replace(" ", "");
            ArrayList<String> signs = new ArrayList<>();
            signs.add("");
            for (char c : exp.toCharArray()){
                if (c == '+' || c == '-')
                    signs.add(Character.toString(c));
            }
            String[] adds = exp.split("[+-]");
            String shit = "";
            int cnt = 0;
            for (int i = 0; i < adds.length; i++){
                if (adds[i].contains("X")){
                    adds[i] = proc(adds[i], true);
                }
                shit += signs.get(cnt++) + adds[i];
            }

            shit = proc(shit, false);

            System.out.println(shit.substring(1, shit.length() - 1));
        }
    }
}
