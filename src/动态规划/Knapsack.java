package 动态规划;

public class Knapsack {
	public int[][] m;
	
	public int n;
	public int c;
	public int[] w;
	public int[] v;
	
	
	public Knapsack(int n, int c, int[] w, int[] v) {
		this.n= n;
		this.c = c;
		this.w = w;
		this.v = v;
	}
	
	public int solve() {
		m = new int[this.n + 1][this.c + 1];
		
		for(int j=0; j<=c; j++) {
			if(j < w[n]) {
				m[n][j] = 0;
			} else {
				m[n][j] = v[n];
			}
		}
		
		for(int i=n-1; i>=1; i--) {
			for(int j=0; j<=c; j++) {
				if(j < w[i]) {
					m[i][j] = m[i+1][j];
				} else {
					m[i][j] = m[i+1][j-w[i]] + v[i] > m[i+1][j] ? m[i+1][j-w[i]] + v[i]:m[i+1][j];
				}
			}
		}
		
		return m[1][c];
	}
	
	public int[] tracback() {
		int[] x = new int[this.n + 1];
		for(int i=1; i<n; i++) {
			if(m[i][c] == m[i+1][c]) {
				x[i] = 0;
			} else {
				x[i] = 1;
				c -= w[i];
			}
		}
		x[n] = (m[n][c] != 0) ? 1:0;
		for(int i=1; i<x.length; i++) {
			if(x[i] == 1) {
				System.out.println("选择背包" + i);
			}
		}
		return x;
	}
	
	public static void main(String[] args) {
		int n = 5, c = 10;
		int[] w = {0, 2, 2, 6, 5, 4}, v = {0, 6, 3, 5, 4, 6};
		Knapsack knapsack = new Knapsack(n, c, w, v);
		System.out.println("总价值最大为：" + knapsack.solve());
		System.out.println("选择背包最优解为:");
		knapsack.tracback();

	}

}
