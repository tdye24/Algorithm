package »ªÊ¦´óCS2018CAMP;

import java.util.Scanner;
import java.io.BufferedInputStream;;
public class Problem2333 {
	
	public static void solve(int b[]) {
		for(int i=0; i<b.length; i++) {
			System.out.println(b[i]/3);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int T = sc.nextInt();
		int b[] = new int[T];
		for(int i=0; i<T; i++) {
			b[i] = sc.nextInt();
		}
		solve(b);
	}

}
