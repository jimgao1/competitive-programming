import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class P3 {

    public static Scanner sc;

    public static int N, X, Y, Z;
    public static String[] A;

    public static ArrayList<Integer> ans;

    public static void init() {
        ans = new ArrayList<>();
    }

    public static void solve() {
        N = sc.nextInt();
        X = sc.nextInt();
        Y = sc.nextInt();
        Z = sc.nextInt();

        A = new String[N];

        sc.nextLine();

        for (int i = 0; i < N; i++) {
            String str = sc.next();
            String out = "";

            for (int j = 0; j < str.length(); j++) {
                int n = str.charAt(j) - '0';

                if ((str.charAt(j) - '0') % 2 == 0) {
                    if (str.charAt(j) == '0') {
                        out += Z;
                    } else {
                        n += X;
                        out += n;
                    }
                } else {
                    n -= Y;
                    if (n < 0) {
                        out += "0";
                    } else {
                        out += n;
                    }
                }
            }

            A[i] = out;
        }

        sc.next();

        for (int i = 0; i < N; i++) {
            if (!sc.next().equals(A[i]))
                ans.add(i + 1);
        }

        sc.next();

        if (ans.size() == 0) {
            System.out.println("MATCH");
        } else {
            System.out.printf("FAIL: ");
            for (int i = 0; i < ans.size(); i++) {
                if (i > 0) System.out.printf(",");
                System.out.printf("%d", ans.get(i));
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws Throwable {
        sc = new Scanner(new File("/tmp/DATA31.txt"));
//        sc = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            init();
            solve();
        }
    }
}

