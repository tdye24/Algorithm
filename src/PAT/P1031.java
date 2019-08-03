package PAT;

import java.util.*;
import java.io.*;
public class P1031 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		String s = sc.next();
		sc.close();
		int N = s.length();
		int N1, N2, N3;
		N1 = N3 = (N+2)/3;
		N2 = N-N1-N3+2;
		int N4 = N2-2;
		for(int i=0; i<N1-1; i++) {
			System.out.print(s.charAt(i));
			for(int j=0; j<N4; j++) {
				System.out.print(" ");
			}
			System.out.println(s.charAt(N-1-i));
		}
		for(int i=N1-1; i<=N-N3; i++) {
			System.out.print(s.charAt(i));
		}
	}

}
