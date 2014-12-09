import java.util.Scanner;
import java.util.Stack;

public class POJ_1028 {
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		Stack<String> backward = new Stack<String>();
		Stack<String> forward = new Stack<String>();
		
		String current = "http://www.acm.org/";
		
		while(true){
			String command = keyboard.next();
			String url = "";
			
			if (command.equals("QUIT")) break;
			
			if (command.equals("VISIT")) {
				url = keyboard.next();
				backward.push(current);
				while(!forward.isEmpty()) forward.pop();
				current = url;
				System.out.println(url);
			}
			
			if (command.equals("BACK")){
				if (backward.isEmpty()){
					System.out.println("Ignored");
				} else {
					forward.push(current);
					current = backward.pop();
					System.out.println(current);
				}
			}
			
			if (command.equals("FORWARD")){
				if (forward.isEmpty()){
					System.out.println("Ignored");
				} else {
					backward.push(current);
					current = forward.pop();
					System.out.println(current);
				}
			}
		}
	}
}
