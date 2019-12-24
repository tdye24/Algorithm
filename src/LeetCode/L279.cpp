/*给定正整数n，找到若干个完全平方数（比如1, 4, 9, 16, ...）
使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
示例1:
输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.

示例 2:
输入: n = 13
输出: 2
解释: 13 = 4 + 9.
*/
#include<bits/stdc++.h>
using namespace std;

int numSquares(int n) {
	int dp[10010];
	fill(dp, dp+10010, 10e8);
	dp[0] = 0;
	dp[1] = 1;	
	for(int i=2; i<=n; i++) {
		for(int j=1; i-j*j>=0; j++)
			dp[i] = min(dp[i], dp[i-j*j]+1);
	}
	return dp[n];   
}

int main() {
	printf("%d", numSquares(12));
	return 0;
}
 
