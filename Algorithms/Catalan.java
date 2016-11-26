import java.math.BigInteger;
import java.util.Scanner;

public class Catalan {
    public static BigInteger factorial(int n){
        BigInteger ans = BigInteger.ONE;
        for (int i = 2; i <= n; i++){
            ans = ans.multiply(new BigInteger(Integer.toString(i)));
        }
        return ans;
    }

    public static BigInteger catalan(int n){
        return BigInteger.ONE
                .multiply(factorial(2 * n))
                .divide(factorial(n + 1))
                .divide(factorial(n));
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        while(sc.hasNext()){
            int n = sc.nextInt();
            System.out.println(catalan(n).toString());
        }
    }
}

