package HUD;

import java.io.*;
import java.util.*;
public class HDU5616Reno {
	static final int MAX_N = 24;
	static final int MAX_W = 2400;
	static boolean[] dp = new boolean[MAX_W];
	static int sum = 0;
	static int[] w = new int[MAX_N];
	public static void ini() {
		for(int i=0; i<MAX_W; i++) {
			dp[i] = false;
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int T = sc.nextInt();//测试样例
		for(int t=0; t<T; t++) {
			sum = 0;
			int N = sc.nextInt();//砝码个数
			for(int i=0; i<N; i++) {
				w[i] = sc.nextInt();
				sum += w[i];
			}
			ini();
			dp[0] = true;
			for(int i=0; i<N; i++) {
				for(int j=sum; j>=w[i]; j--) {
					dp[j] |= dp[j-w[i]];
				}
			}
			
			for(int i=0; i<N; i++) {
				for(int j=0; j+w[i]<=sum; j++) {
					dp[j] |= dp[j+w[i]];
				}
			}
			int M = sc.nextInt();//查询次数
			for(int q=0; q<M; q++) {
				int weight = sc.nextInt();
				if(dp[weight]) {
					System.out.println("YES");
				} else {
					System.out.println("NO");
				}
			}
		}

	}

}
