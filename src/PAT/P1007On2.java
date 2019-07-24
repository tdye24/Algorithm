package PAT;

import java.util.*;
import java.io.*;
public class P1007On2 {
	static int MAX = 100024;
	static int N;
	static int[] a = new int[MAX];
	static int besti;
	static int bestj;
	static int solve() {
		int sum = -1;
		
		for(int i=0; i<N; i++) {
			int thissum = 0;
			for(int j=i; j<N; j++) {
				thissum += a[j];
				if(thissum > sum) {
					sum = thissum;
					besti = i;
					bestj = j;
				}
			}
		}
		return sum;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		N = sc.nextInt();
		for(int i=0; i<N; i++) {
			a[i] = sc.nextInt();
		}
		besti = 0;
		bestj = N-1;
		int sum = solve();
		if(sum < 0)
			sum = 0;
		System.out.print(sum + " " + a[besti] + " " + a[bestj]);
		
		sc.close();
	}

}
