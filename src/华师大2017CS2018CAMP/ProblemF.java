package »ªÊ¦´ó2017CS2018CAMP;

import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;
public class ProblemF {
	public static int INF = Integer.MAX_VALUE;
	public static void statistic(int[] a, int i, int j) {
		int sum = 0;
		
		int b[] = new int[j-i+2];
		
		for(int t=i-1; t<j; t++) {
			b[t-i+1] = a[t];
		}
		
		
		b[j-i+1] = INF;
		Arrays.sort(b, 0, j-i+2);
		
		int n = j-i+2;
		for(int t=0; t<n-1; t++) {
			if(b[t] == b[t+1]) {
				sum ++;
				if(b[t+1] == b[t+2]) {
					sum --;
					t += 2;
					while(b[t] == b[t+1]) {
						t ++;
					}
				} else {
					t ++;
				}
			}
		}
		
		
		
		System.out.println(sum);
		
	}
	
	public static void solve(int N, int Q, int[] a, int[][] b) {
		for(int i=0; i<Q; i++) {
			statistic(a, b[i][0], b[i][1]);
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int N = sc.nextInt();
		int Q = sc.nextInt();
		
		int a[] = new int[N];
		for(int i=0; i<N; i++) {
			a[i] = sc.nextInt();
		}
		
		int b[][] = new int[Q][2];
		for(int i=0; i<Q; i++) {
			b[i][0] = sc.nextInt();
			b[i][1] = sc.nextInt();
		}
		
		solve(N, Q, a, b);

	}

}
