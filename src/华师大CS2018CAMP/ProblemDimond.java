package »ªÊ¦´óCS2018CAMP;

import java.util.Scanner;
import java.io.BufferedInputStream;
public class ProblemDimond {
	public static int V[] = {1, 5, 10, 25};
	public static void solve(int P, int[] N, int money_count) {
		int ans = 0;
		
		for(int i=3; i>=0; i--) {
			int t = Math.min(P/V[i], N[i]);
			P -= t*V[i];
			ans += t;
		}
		if(P == 0) {
			System.out.println(money_count - ans);
			return ;
		} else {
			
			System.out.println("Impossible");
		}
		
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int money_sum = 0;
		int money_count = 0;
		int P = sc.nextInt();
		int N[] = new int[4];
		for(int i=0; i<4; i++) {
			N[i] = sc.nextInt();
			money_sum += V[i]*N[i];
			money_count += N[i];
		}
		
		
		solve(money_sum - P, N, money_count);

	}

}
