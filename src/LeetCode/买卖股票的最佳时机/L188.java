package LeetCode.买卖股票的最佳时机;

public class L188 {
	public static int maxProfit_k_inf(int[] prices) {
	    int n = prices.length;
	    int dp_i_0 = 0, dp_i_1 = -prices[0];
	    for (int i = 0; i < n; i++) {
	        int temp = dp_i_0;
	        dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
	        dp_i_1 = Math.max(dp_i_1, temp - prices[i]);
	    }
	    return dp_i_0;
	}

	public static int maxProfit_k_any(int max_k, int[] prices) {
	    int n = prices.length;
	    if(n == 0)
	        return 0;
	    if (max_k > n / 2) 
	        return maxProfit_k_inf(prices);

	    int[][][] dp = new int[n][max_k + 1][2];
	    for (int i = 0; i < n; i++) 
	        for (int k = max_k; k >= 1; k--) {
	            if (i - 1 == -1) { 
	                /* 处理 base case */ 
	                dp[i][k][0] = 0;
	                dp[i][k][1] = -prices[i];
	                continue;
	            }
	            dp[i][k][0] = Math.max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
	            dp[i][k][1] = Math.max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);     
	        }
	    return dp[n - 1][max_k][0];
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] prices = new int[] {3,2,6,5,0,3};
		int k = 2;
		System.out.println(maxProfit_k_any(k, prices));
	}

}
