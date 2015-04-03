import java.util.Arrays;

public class Polygon {
	/*------------------------------------------------------------------*/
	//Implementation of point
	public static class Point implements Comparable<Point>{
		int x, y;
		@Override
		public int compareTo(Point p) {
			if (this.x == p.x)
				return this.y - p.y;
			else 
				return this.x - p.x;
		}
		public String toString() {
			return "(" + x + "," + y + ")";
		}
	}
	/*------------------------------------------------------------------*/
	//Computes convex hull and returns in clockwise order	
	public static long cross(Point O, Point A, Point B) {
		return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
	}
	public static Point[] convexHull(Point[] P) {
		int n = P.length, k = 0;
		Point[] H = new Point[2 * n];
		Arrays.sort(P);
		//compute top hull
		for (int i = 0; i < n; ++i) {
			while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
				k--;
			H[k++] = P[i];
		}
		//compute bot hull
		for (int i = n - 2, t = k + 1; i >= 0; i--) {
			while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0)
				k--;
			H[k++] = P[i];
		}
		if (k > 1) {
			H = Arrays.copyOfRange(H, 0, k - 1); //remove the last index
		}
		return H;
	}
	/*------------------------------------------------------------------*/
	//Computes area of a polygon points must be in clockwise order
	public static double polyArea(Point[] polyPoints) {
		int i, j, n = polyPoints.length;
		double area = 0;
		for (i = 0; i < n; i++) {
			j = (i + 1) % n;
			area += polyPoints[i].x * polyPoints[j].y;
			area -= polyPoints[j].x * polyPoints[i].y;
		}
		area /= 2.0;
		return area;
	}
}
