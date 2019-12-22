package LeetCode.买卖股票的最佳时机;

public class L714 {
	public static int maxProfit_with_fee(int[] prices, int fee) {
	    int n = prices.length;
	    int dp_i_0 = 0, dp_i_1 = -prices[0]-fee;
	    for (int i = 0; i < n; i++) {
	        int temp = dp_i_0;
	        dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
	        dp_i_1 = Math.max(dp_i_1, temp - prices[i] - fee);
	    }
	    return dp_i_0;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] prices = new int[] {1, 3, 2, 8, 4, 9};
		int fee = 2;
		System.out.println(maxProfit_with_fee(prices, fee));
		
	}

}
