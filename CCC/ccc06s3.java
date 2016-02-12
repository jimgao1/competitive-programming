package asd;

import java.awt.Point;
import java.awt.geom.Line2D;
import java.util.ArrayList;
import java.util.Scanner;

public class ccc06s3 {
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		Line2D init = new Line2D.Float(keyboard.nextInt(), keyboard.nextInt(), 
										keyboard.nextInt(), keyboard.nextInt());
		
		int ans = 0;
		
		int bcnt = keyboard.nextInt();
		
		for (int i = 0; i < bcnt; i++){
			boolean flag = false;
			
			int pcnt = keyboard.nextInt();
			
			ArrayList<Point> pnt = new ArrayList<>();
			for (int j = 0; j < pcnt; j++){
				pnt.add(new Point(keyboard.nextInt(), keyboard.nextInt()));
			}
			
			for (int j = 0; j < pcnt; j++){
				Line2D ln = new Line2D.Float(pnt.get(j).x, pnt.get(j).y,
											pnt.get((j + 1) % pcnt).x, pnt.get((j + 1) % pcnt).y);
				
				if (init.intersectsLine(ln)){
					flag = true;
				}
			}
			
			if (flag) ans++;
		}
		
		System.out.println(ans);
	}
}
