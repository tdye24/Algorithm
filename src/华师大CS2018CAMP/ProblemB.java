package »ªÊ¦´óCS2018CAMP;

import java.util.Scanner;
import java.io.BufferedInputStream;
import java.util.HashMap;
import java.util.Map;
public class ProblemB {
	class Result {
		int max;
		int b[];
		
		public Result(int max, int b[]) {
			this.max = max;
			this.b = b;
		}
		
		public void setMax(int max) {
			this.max = max;
		}
		
		public void setB(int b[]) {
			this.b = b;
		}
		
		public int getMax() {
			return this.max;
		}
		
		public int[] getB() {
			return this.b;
		}
	}
	
	public static int gcd(int a, int b) {
		if(a < b) {
			int t =a;
			a = b;
			b = t;
		}
        return a%b==0 ? b : gcd(b, a%b);
    }
	
	public static Result statistic(int n, int m, int a[][], Result result) {
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
		result.setMax(max);
		result.setB(b);
		
		return result;
	}
	
	public static void average(int b[], int m) {
		int sum = 0;
		for(int i=1; i<m+1; i++) {
			sum += b[i];
		}
		int gcd = gcd(sum, m);
		System.out.println((int)sum/gcd + "/" + (int)m/gcd);
		
	}
	
	public static void solve(int n, int m, int a[][], int q, Result result) {
		result = statistic(n, m, a, result);
		int b[] = new int[m+1];
		switch(q) {
			case 1:
				System.out.println(result.getMax());
				break;
			case 2:
				average(result.getB(), m);
				break;
			case 3:
				System.out.println(result.getMax());
				average(result.getB(), m);
				break;
			default:
				
		}
			
	}
//	public static void main(String[] args) {
//	
//		Scanner sc = new Scanner(new BufferedInputStream(System.in));
//		
//		int n = sc.nextInt();
//		int m = sc.nextInt();
//		
//		int b[] = new int[m+1];
//		
//		Result result = new ProblemB().new Result(0, b);
//		
//		int a[][] = new int[n][2];
//		for(int i=0; i<n; i++) {
//			a[i][0] = sc.nextInt();
//			a[i][1] = sc.nextInt();
//		}
//		int q = sc.nextInt();
//		
//		solve(n, m, a, q, result);
//
//	}

	public static void main(String[] args) {
		
		int n = (int)(1 + Math.random()*1000);
		int m = (int)(1 + Math.random()*25000);
		System.out.println("n=" + n);
		System.out.println("m=" + m);
		
		int b[] = new int[m+1];
		
		Result result = new ProblemB().new Result(0, b);
		
		int a[][] = new int[n][2];
		for(int i=0; i<n; i++) {
			a[i][0] = (int)(1 + Math.random()*m);
			System.out.print(a[i][0] + " ");
			a[i][1] = (int)(a[i][0] + Math.random()*m);
			System.out.println(a[i][1]);
		}
		int q = (int)(1 + Math.random()*3);
		
		solve(n, m, a, q, result);

	}
}
