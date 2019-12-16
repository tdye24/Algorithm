/*给定两个有序整数数组nums1 和 nums2，将 nums2 合并到?nums1?中，使得?num1 成为一个有序数组。
说明:
初始化nums1和nums2的元素数量分别为m和n。
你可以假设nums1有足够的空间（空间大小大于或等于m + n）来保存 nums2 中的元素。
示例:
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
输出:[1,2,2,3,5,6]
*/
#include<bits/stdc++.h>
using namespace std;

//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//	for(int i=m, j=0; i<m+n && j<n; i++, j++) 
//		nums1[i] = nums2[j];
//	sort(nums1.begin(), nums1.end());
//}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector<int> copy;
	for(int i = 0; i < m; i++) 
		copy.push_back(nums1[i]);
	int i = 0, j = 0, t = 0;
	while(i < m && j < n) 
		nums1[t++] = (copy[i] <= nums2[j]) ? copy[i++] : nums2[j++];	
	while(i < m)
		nums1[t++] = copy[i++];
	while(j < n)
		nums1[t++] = nums2[j++];	
}

int main() {
	vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
	merge(nums1, 3, nums2, 3);
	for(int i=0; i<6; i++) 
		cout << nums1[i] << " ";
	return 0;
}
