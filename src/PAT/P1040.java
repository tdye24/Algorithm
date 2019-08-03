package PAT;

import java.util.*;
import java.io.*;
public class P1040 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		String s = sc.nextLine();
		sc.close();
		int len = s.length();
		boolean[][] DP = new boolean[len][len];
		for(int i=0; i<len; i++) {
			DP[i][i] = true;
		}
		int besti = 0;
		int bestj = 0;
		/*
		 * 倒序是为了维护较前的最长回文串
		 */

		for(int i=len-2; i>=0; i--) {
			if(s.charAt(i) == s.charAt(i+1)) {
				DP[i][i+1] = true;
				besti = i;
				bestj = i+1;
			}
				
		}
		
		for(int i=2; i<len; i++) {
			for(int j=len-1; j-i>=0; j--) {
				if(s.charAt(j-i) == s.charAt(j)) {
					DP[j-i][j] = DP[j-i+1][j-1];
					if(DP[j-i][j]) {
						besti = j-i;
						bestj = j;
					}
					
				}
					
			}
		}
		System.out.print(bestj-besti+1);
	}
}