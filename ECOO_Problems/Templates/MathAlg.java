
public class MathAlg {
	/*------------------------------------------------------------------*/
	//radius of circumcenter of a triangle or circle that touches all 3 points
	public static double radiusOfCircumcenter(double a, double b, double c){
		double numerator = (a * b * c);
		double denominator = Math.sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c));
		double circR = (numerator / denominator) * 2;
		return circR;
	}
	
	public static double radiusOfCircumcenterEquilateral(double s){
		return s / Math.sqrt(3);
	}
	
	public static double radiusOfCircumcenterSideAndOppositeAngle(double a, double angle){
		return a / Math.toDegrees(Math.sin(angle));
	}
	
	/*------------------------------------------------------------------*/
	//Finds lcm and gcd
	private static long gcd(long a, long b)
	{
	    while (b > 0)
	    {
	        long temp = b;
	        b = a % b;
	        a = temp;
	    }
	    return a;
	}
	private static long gcd(long[] input)
	{
	    long result = input[0];
	    for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
	    return result;
	}
	private static long lcm(long a, long b)
	{
	    return a * (b / gcd(a, b));
	}

	private static long lcm(long[] input)
	{
	    long result = input[0];
	    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
	    return result;
	}
}
