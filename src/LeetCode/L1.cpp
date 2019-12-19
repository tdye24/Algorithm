#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	int n = nums.size(), another;
	vector<int> ans;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(nums[i]+nums[j] == target) {
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}
		}
	}
	return ans;
}

int main() {
	vector<int> nums = {3, 2, 4};
	vector<int> ans = twoSum(nums, 6);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;	
} 
