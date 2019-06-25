package »ªÊ¦´ó2017CS2018CAMP;

import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;
public class ProblemF {
	public static void statistic(int[] a, int i, int j) {
		int sum = 0;
		Arrays.sort(a, i, j);
	
		for(int t=i; t<j; t++) {
			if(t+1 >= j) {
				System.out.println(sum);
				return ;
			}
			if(a[t] == a[t+1]) {
				sum ++;
				if(t+2 >= j) {
					System.out.println(sum);
					return ;
				}
				if(a[t+1] == a[t+2]) {
					sum --;
					t += 3;
					if(t >= j) {
						System.out.println(sum);
						return ;
					}
					while(a[t] == a[t-1]) {
						if(t >= j) {
							System.out.println(sum);
							return ;
						}
						t++;
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
			statistic(a, b[i][0]-1, b[i][1]);
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
