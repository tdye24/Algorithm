package »ªÊ¦´óCS2018CAMP;

import java.io.BufferedInputStream;
import java.util.Scanner;

public class ProblemA {

	public static void solve(int[][] a, int n, int m, int[][] b, int h, int w) {
		
		int c[][] = new int[n-h+1][m-w+1];
		for(int i=0; i<=n-h; i++) {
			for(int j=0; j<=m-w; j++) {
				for(int p=0; p<h; p++) {
					for(int q=0; q<w; q++) {
						c[i][j] += b[p][q]*a[i+p][j+q];
					}
				}
			}
		}
		for(int i=0; i<n-h+1; i++) {
			for(int j=0; j<m-w+1; j++) {
				System.out.print(c[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		
		int n = in.nextInt();
		int m = in.nextInt();
		
		int a[][] = new int[n][m];
		
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				a[i][j] = in.nextInt();
			}
		}
		
		int h = in.nextInt();
		int w = in.nextInt();
		
		int b[][] = new int[h][w];
		
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				b[i][j] = in.nextInt();
			}
		}
		solve(a, n, m, b, h, w);
	}

}
