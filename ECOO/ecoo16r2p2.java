import java.util.Scanner;

public class ecoo16r2p2 {
	
	public static int calc(String str){
		return (str.charAt(0) - 'a') * 26 + (str.charAt(1) - 'a');
	}
	
	public static String calc2(int len){
		return "" + (char)((len / 26) + 'a') + (char)((len % 26) + 'a');
	}
	
	public static char rotate(char c, int k){
		k = k % 26;
		c += k;
		while(c < 'a') c += 26;
		while(c > 'z') c -= 26;
		return c;
	}
	
	public static String encrypt(String line, int K){
		String[] tokens = line.split(" ");
		
		String tmp = "";
		tmp += (calc2(tokens.length));
		for (int i = 0; i < tokens.length; i++){
			tmp += (char)(tokens[i].length() + 'a');
		}
		for (int i = 0; i < tokens.length; i++){
			tmp += tokens[i];
		}
		
		tmp = new StringBuilder(tmp).reverse().toString();

		int sum = K;
		String ans = "";
		for (int i = 0; i < tmp.length(); i++){
			ans += rotate(tmp.charAt(i), sum);
			sum += (tmp.charAt(i) - 'a');
		}
		
		return new StringBuilder(ans).reverse().toString();
	}
	
	public static String decrypt(String line, int K){
		String tmp = new StringBuilder(line).reverse().toString();
		String ans1 = "";
		int sum = K;
		for (int i = 0; i < tmp.length(); i++){
			ans1 += rotate(tmp.charAt(i), -sum);
			sum += ans1.charAt(i) - 'a';
		}
		ans1 = new StringBuilder(ans1).reverse().toString();
		
		int words = calc(ans1.substring(0, 2));
		int[] len = new int[words];
		for (int i = 0; i < words; i++){
			len[i] = ans1.charAt(2 + i) - 'a';
		}
		
		ans1 = ans1.substring(2 + words);
		
		String fuck = "";
		int idx = 0;
		for (int i = 0; i < words; i++){
			fuck += ans1.substring(idx, idx + len[i]) + " ";
			idx += len[i];
		}
		
		return fuck;
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int T = 10;
		while(T-- != 0){
			int K = Integer.parseInt(sc.nextLine());
			String str = sc.nextLine();
			
			if (str.contains(" ")){
				System.out.println(encrypt(str, K));
			} else {
				System.out.println(decrypt(str, K));
			}
		}
	}
}

