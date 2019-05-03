package 动态规划;

public class LCSLength {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char[] x = {'a', 'm', 'e', 'd'};
		char[] y = {'a', 'b', 'c', 'd'};
		int[][] c = new int[x.length+1][y.length+1];
		int[][] b = new int[x.length+1][y.length+1];
		System.out.println("最长公共子序列：");
		System.out.println(LCSLength.LCSLength_(x.length, y.length, x, y, c, b));
	}
	
	public static int LCSLength_(int m, int n, char[] x, char[] y,  int[][] c, int[][] b) {
		int i, j;
		for(i=1; i<=m; i++) c[i][0]=0;
		for(j=1; i<=n; j++) c[0][i]=0;
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++) {
				if(x[i]==y[j]) {
					c[i+1][j+1] = c[i][j] + 1;
					b[i+1][j+1] = 1;
				} else if(c[i+1][j]>c[i][j+1]) {
					c[i+1][j+1] = c[i+1][j];
					b[i+1][j+1] = 2;
				} else {
					c[i+1][j+1] = c[i][j+1];
					b[i+1][j+1] = 3;
				}
			}
		}
		return c[m][n];
	}

}
