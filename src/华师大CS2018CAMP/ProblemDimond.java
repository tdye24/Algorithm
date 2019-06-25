package »ªÊ¦´óCS2018CAMP;

import java.util.Scanner;
import java.io.BufferedInputStream;
public class ProblemDimond {
	public static void solve(int P, int[] N) {
		int P_ = P;
		int ans = 0;
		int V[] = {1, 5, 10, 25};
		for(int i=0; i<4; i++) {
			int t = Math.min(P/V[i], N[i]);
			P -= t*V[i];
			ans += t;
		}
		if(P == 0) {
			System.out.println(ans);
			return ;
		} else {
			int max = 0;
			ans = 0;
			for(int i=0; i<=N[0]; i++) {
				for(int j=0; j<=N[1]; j++) {
					for(int p=0; p<=N[2]; p++) {
						for(int q=0; q<=N[3]; q++) {
							int temp = P_ - V[0]*i - V[1]*j - V[2]*p - V[3]*q;
							if(temp == 0) {
								max = i+j+p+q;
								if(max > ans) {
									ans = max;
								}
							}
						}
					}
				}
			}
			if(ans != 0) {
				System.out.println(ans);
				return ;
			}
			System.out.println("Impossible");
			return ;
		}
		
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int P = sc.nextInt();
		int N[] = new int[4];
		for(int i=0; i<4; i++) {
			N[i] = sc.nextInt();
		}
		solve(P, N);

	}

}
