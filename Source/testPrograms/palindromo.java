import java.util.Scanner;

public class palindromo{
	public static boolean stop(String s){
		if(s.length()==3 && s.charAt(0)=='F' && s.charAt(1)=='I' && s.charAt(2)=='M') return true;
		else return false;
	}

	public static boolean pali(String s){
		int i = 0,
			f = s.length()-1;
		boolean result = true;
		while(result && i!=f && i<s.length()/2){
			if(s.charAt(i) != s.charAt(f)) result = false;
			i++;
			f--;
		}
		return result;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String input = null;
		boolean stop = false;
		while(!stop){
			input = sc.nextLine();
			if(stop(input)) stop = true;
			else if(pali(input)) System.out.println("SIM");
			else System.out.println("NAO");
		}
	}
}
