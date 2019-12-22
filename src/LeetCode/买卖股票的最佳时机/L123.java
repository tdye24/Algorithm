package LeetCode.买卖股票的最佳时机;

public class L123 {
	public static int maxProfit(int[] prices) {
	    int n = prices.length;
	    if(n == 0)
	        return 0;
	    int max_k = 2;
	    int[][][] dp = new int[n][max_k + 1][2];
	    for (int i = 0; i < n; i++) {
	        for (int k = max_k; k >= 1; k--) {
	            //或者for(int k=1; k<=max_k; k++)
	            if (i - 1 == -1) { 
	                dp[i][k][0] = 0;
	                dp[i][k][1] = -prices[i];
	                continue;
	            }
	            dp[i][k][0] = Math.max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
	            dp[i][k][1] = Math.max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
	        }
	    }
	    // 穷举了 n × max_k × 2 个状态，正确。
	    return dp[n - 1][max_k][0];
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] prices = new int[] {3,3,5,0,0,3,1,4};
		System.out.println(maxProfit(prices));

	}

}
