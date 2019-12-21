#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
	if(prices.size() == 0) 
		return 0;
	int sum = 0, left = prices[0], right = -1, count = 1;
	for(int i=1; i<prices.size(); i++) {
		if(prices[i] >= prices[i-1]) {
			right = prices[i];
			if(i == prices.size()-1) 
				sum += (right-left);	
		} else if(right != -1) {
			sum += (right-left);
			left = prices[i];
			right = -1;
		} else {
			left = prices[i];
		}
	}
        
    return sum;
}

int main() {
	vector<int> prices = {7,6,4,3,1};
	cout << maxProfit(prices) << endl;
	return 0;
}
