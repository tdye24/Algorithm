package Ì°ĞÄ·¨;

public class Coin {
	public static int solve(int[] V, int[] C, int A) {
		int ans = 0;
		for(int i=5; i>=0; i--) {
			int t = A/V[i] > C[i] ? C[i]:A/V[i];
			A -= t*V[i];
			ans += t;
		}
		return ans;
	}
	
	public static void main(String[] args) {
		int[] V = {1, 5, 10, 50, 100, 500};
		int[] C = {3, 2, 1, 3, 0, 2};
		int A = 620;
		System.out.println(solve(V, C, A));
	}

}
