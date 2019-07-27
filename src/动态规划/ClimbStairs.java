package ¶¯Ì¬¹æ»®;

import java.util.*;
import java.io.*;
public class ClimbStairs {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int n = sc.nextInt();
		int[] dp = new int[1024];
		dp[0] = 1;
		dp[1] = 1;
		for(int i=2; i<=n; i++) {
			dp[i] = dp[i-1]+dp[i-2];
		}
		System.out.print(dp[n]);

	}

}
