package 动态规划;

public class MatrixMultiply {
	public static void matrixChain(int[] p, int n, int[][] m, int[][] s) {
		for(int i=1; i<=n; i++) m[i][i] = 0;
		for(int r=2; r<=n; r++) {
			for(int i=1; i<=n-r+1; i++) {
				int j = i+r-1;
				m[i][j] = m[i][i] + m[i+1][j] + p[i-1]*p[i]*p[j];
				s[i][j] = i;
				for(int k=i+1; k<j; k++) {
					int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
					if(t < m[i][j]) { m[i][j] = t; s[i][j] = k;}
				}
			}
		}
		
	}
	
	public static void traceBack(int i, int j, int[][] s) {
		if(i == j) return;
		traceBack(i, s[i][j], s);
		traceBack(s[i][j] + 1, j, s);
		System.out.println("Multiply A" + i + "," + s[i][j] + "and A" + (s[i][j]+1) + "," + j);	
	}
	
	public static void main(String[] args) {
		int[] p = {30, 35, 15, 5, 10, 20, 25};
		int m[][] = new int[p.length][p.length];
		int s[][] = new int[p.length][p.length];
		matrixChain(p, 6, m, s);
		System.out.println("最小计算量为：" + m[1][p.length-1]);
		traceBack(1, 6, s);

	}

}
