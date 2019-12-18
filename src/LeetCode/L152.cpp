#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int imax = 1, imin = 1, ans = -10e8;
    for(int i=0; i<nums.size(); i++) {
    	if(nums[i] < 0) 
    		swap(imax, imin);
    	imax = max(imax*nums[i], nums[i]);
    	imin = min(imin*nums[i], nums[i]);
    	ans = max(ans, imax);
	}
	return ans;
}

int main() {
	vector<int> vec = {-2,0,-1};
	printf("%d", maxProduct(vec));
	return 0;
}
