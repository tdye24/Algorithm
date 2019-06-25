package hunan;

import java.util.Scanner;

public class Main {
	int n;
	String str;
	public Main(int n, String str) {
		this.n= n;
		this.str = str;
	}
	
	public boolean is(int n, String str) {
		for(int i=1; i<n-1; i++) {
			if(str.charAt(i+1) == str.charAt(i-1)) {
				return true;
			} 
		}
		for(int i=0; i<n-1; i++) {
			if(str.charAt(i) == str.charAt(i+1)) {
				return true;
			} 
		}
		return false;
	}
	
	public void solve() {
		if(is(this.n, this.str)) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		Main problem = new Main(scanner.nextInt(), scanner.next());
		problem.solve();
	}

}
