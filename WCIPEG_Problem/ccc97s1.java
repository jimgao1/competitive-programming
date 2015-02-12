import java.util.Scanner;

public class ccc97s1 {
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		int caseCount = keyboard.nextInt();
		
		while(caseCount-- != 0){
			int subjectCount = keyboard.nextInt();
			int verbCount = keyboard.nextInt();
			int objectCount = keyboard.nextInt();
			
			keyboard.nextLine();
			
			String[] subjects = new String[subjectCount];
			String[] verbs = new String[verbCount];
			String[] objects = new String[objectCount];
			
			for (int i=0; i<subjectCount; i++)
				subjects[i] = keyboard.nextLine();
			
			for (int i=0; i<verbCount; i++)
				verbs[i] = keyboard.nextLine();
			
			for (int i=0; i<objectCount; i++)
				objects[i] = keyboard.nextLine();
			
			for (int i=0; i<subjectCount; i++)
				for (int j=0; j<verbCount; j++)
					for (int k=0; k<objectCount; k++)
						System.out.printf("%s %s %s.\n", subjects[i], verbs[j], objects[k]);
		}
	}
}
