package »ªÊ¦´ó2017CS2018CAMP;

import java.io.BufferedInputStream;
import java.util.Scanner;
public class ProblemC {
	public static int min(int a, int b) {
		return a > b ? b:a;
	}
	
	public static void solve(int n, int x, int y) {
		int cost[] = new int[n+1];
		for(int i=1; i<=n; i++) {
			if(i == 1) {
				cost[i] = x;
			} else {
				int A = cost[i-1] + x;
				if(i%2 == 1) {
					int E = cost[(i+1)/2] + x + y;
					int F = cost[(i-1)/2] + x + y;
					cost[i] = min(F, min(A, E));
				} else {
					int D = cost[(int)(i/2)] + y;
					cost[i] = min(A, D);
				}
			}
		}
		System.out.println(cost[n]);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int n = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		solve(n, x, y);
	}

}
