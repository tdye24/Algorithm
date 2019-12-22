package LeetCode.买卖股票的最佳时机;

public class L122 {
	public static int maxProfit_k_inf(int[] prices) {
	    int n = prices.length;
	    if(n == 0)
	    	return 0;
	    int dp_i_0 = 0, dp_i_1 = -prices[0];
	    for (int i = 0; i < n; i++) {
	        int temp = dp_i_0;
	        dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
	        dp_i_1 = Math.max(dp_i_1, temp - prices[i]);
	    }
	    return dp_i_0;
	}
	public static void main(String[] args) {
		int[] prices = new int[] {7,1,5,3,6,4};
		System.out.println(maxProfit_k_inf(prices));

	}

}
