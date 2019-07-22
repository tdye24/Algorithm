package 动态规划;

import java.io.*;
import java.util.*;
public class TSP {
	static int n;
	static final int MAX_N = 24;
	static int[][] d = new int[MAX_N][MAX_N];
	static int[][] dp = new int[1 << MAX_N][MAX_N]; //记忆化搜索使用的数组
	static int rec(int S, int v) {
		if(dp[S][v] >= 0) {
			return dp[S][v];
		}
		
		if(S == (1<<n)-1 && v == 0) {
			return dp[S][v] = 0;
		}
		
		int res = Integer.MAX_VALUE;
		for(int u=0; u<n; u++) {
			if((S>>u & 1) == 0) {
				res = Math.min(res, rec(S|1<<u, u) + d[v][u]);
			}
		}
		return dp[S][v] = res;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		
		for(int i=0; i<dp.length; i++) {
			Arrays.fill(dp[i], -1);
		}
		System.out.printf("%d\n", rec(0, 0));
	}

}
