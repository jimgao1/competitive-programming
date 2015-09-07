/*
ID: jim.yub1
LANG: JAVA
TASK: fence9
*/

import java.io.File;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Scanner;

public class fence9{
	
	public static int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
	
	public static void main(String[] args) throws Exception{
		Scanner input = new Scanner(new File("fence9.in"));
		BufferedWriter output = new BufferedWriter(new FileWriter("fence9.out"));
		
		int n = input.nextInt();
		int m = input.nextInt();
		int p = input.nextInt();
		int border = 0;
		
		//step 1: calculate the area
		double a = p, b = Math.sqrt(n * n + m * m), c = Math.sqrt((n - p) * (n - p) + m * m);
		double s = (a + b + c) / 2;
		double area = Math.sqrt( ( a + ( b + c ) ) * ( c - ( a - b ) ) * ( c + ( a - b ) ) * ( a + ( b - c ) ) ) / 4;

		//cout << "area = " << area << endl;

		//step 2: calculate the border points
		border += p;
		border += gcd(n, m);
		border += gcd(Math.abs(n - p), m);

		//cout << "border = " << border << endl;

		//step 3: calculate interior points
		int ans = (int)(Math.ceil(area) - Math.ceil(border / 2.0) + 1);
		
		output.write(Integer.toString(ans) + "\n");
		
		input.close();
		output.close();
	}
}
