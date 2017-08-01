import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		System.out.println((sc.nextLong() / sc.nextLong()) % 2 == 0 ? "NO" : "YES");
	}
}
