class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long long arr[10010];
        int k = 0;
        for(int i=0; i<nums.size(); i++) {
        	if(nums[i] > 0) {
        		arr[k++] = nums[i];
			}
		}
		sort(arr, arr+k);
		if(k == 0 || arr[0] != 1)
            return 1;
		for(int i=1; i<k; i++) {
			if(arr[i] - arr[i-1] > 1) {
				return arr[i-1] + 1;
			}
		}
		return arr[k-1] + 1;
    }
};
