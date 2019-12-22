package LeetCode.买卖股票的最佳时机;

public class L121 {
	public static int maxProfit(int[] prices) {
		int n = prices.length;
		if(n == 0)
			return 0;
		int [][] dp = new int[n][2];
		for(int i=0; i<n; i++) {
			if(i-1 == -1) {
				dp[i][0] = 0;
				dp[i][1] = -prices[i];
				//dp_i_0 = 0, dp_i_1 = Integer.MIN_VALUE;
				continue;
			}
			dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1]+prices[i]);
			// dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
			dp[i][1] = Math.max(dp[i-1][1], -prices[i]);
			// dp_i_1 = Math.max(dp_i_1, -prices[i]);
		}
		return dp[n-1][0];
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] prices = new int[] {7, 1, 5, 3, 6, 4};
		System.out.println(maxProfit(prices));
	}

}
