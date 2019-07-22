package HUD;

import java.util.*;
import java.io.*;
public class HDU5616 {
	static final int MAX_N = 24;
	static final int MAX_W = 24*100;
	static int[] w = new int[MAX_N];
	static int[][] dp = new int[MAX_N][2*MAX_W+1];//0表示false, 1表示true, 初始化为-1, 表示前i个砝码正反选是否能组成重量为j的砝码组

	static int rec(int i, int j) {
		if(j > 2*MAX_W || j <= 0) 
			return 0;
		if(dp[i][j] > 0) {
			//已经计算过直接使用以前结果
			return dp[i][j];
		}
		int res = 0 ;
		if(j == 2400) {
			res = 1;
		} else if(i == 0) {
			res = (w[i] == (2*MAX_W -  j))||(w[i] == j) ? 1:0;
		} else {
			if((rec(i-1, j-w[i]+MAX_W)|rec(i-1, j+w[i]-MAX_W)|rec(i-1, j)) == 1) {
				res = 1;
			}
		}
		return dp[i][j] = res;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		for(int i=0; i<MAX_N; i++) {
			for(int j=0; j<2*MAX_W+1; j++) {
				dp[i][j] = -1;
			}
		}
		int T = sc.nextInt();//测试样例
		int N = sc.nextInt();//砝码个数
		for(int i=0; i<T; i++) {
			for(int j=0; j<N; j++) {
				w[j] = sc.nextInt()+MAX_W;
			}
			int M = sc.nextInt();//查询次数
			for(int k=0; k<M; k++) {
				System.out.println(rec(N-1, sc.nextInt()+MAX_W) == 1 ? "YES":"NO");
			}
		}
	}
}
