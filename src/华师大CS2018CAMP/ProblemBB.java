package »ªÊ¦´óCS2018CAMP;

import java.util.Scanner;
import java.io.BufferedInputStream;
public class ProblemBB {
	public static int gcd(int a, int b) {
		if(a < b) {
			int t =a;
			a = b;
			b = t;
		}
        return a%b==0 ? b : gcd(b, a%b);
    }
	
	public static void max(int n, int m, int a[][]) {
		int max = 0;
		int b[] = new int[m+1];
		for(int i=0; i<m+1; i++) {
			b[i] = 0;
		}
		for(int i=1; i<=m; i++) {
			for(int j=0; j<n; j++) {
				if(a[j][0] <=i && i<= a[j][1]) {
					b[i] += 1;
				}
			}
			if(b[i] > max) {
				max = b[i];
			}
		}
		System.out.println(max);
	}
	
	public static void average(int n, int m, int a[][]) {
		int sum = 0;
		int b[] = new int[m+1];
		for(int i=0; i<m+1; i++) {
			b[i] = 0;
		}
		for(int i=1; i<=m; i++) {
			for(int j=0; j<n; j++) {
				if(a[j][0] <=i && i<= a[j][1]) {
					b[i] += 1;
				}
			}
		}
		for(int i=1; i<m+1; i++) {
			sum += b[i];
		}
		int gcd = gcd(sum, m);
		System.out.println((int)sum/gcd + "/" + (int)m/gcd);
	}
	
	public static void solve(int n, int m, int a[][], int q) {
		int b[] = new int[m+1];
		switch(q) {
			case 1:
				max(n, m, a);
				break;
			case 2:
				average(n, m, a);
				break;
			case 3:
				max(n, m, a);
				average(n, m, a);
				break;
			default:
				
		}
			
	}
	public static void main(String[] args) {
	
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int b[] = new int[m+1];
		
		int a[][] = new int[n][2];
		for(int i=0; i<n; i++) {
			a[i][0] = sc.nextInt();
			a[i][1] = sc.nextInt();
		}
		int q = sc.nextInt();
		
		solve(n, m, a, q);

	}

}
