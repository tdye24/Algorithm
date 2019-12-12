/*	给定一个未排序的整数数组，找出最长连续序列的长度。
	要求算法的时间复杂度为 O(n)。
	示例:
	输入: [100, 4, 200, 1, 3, 2]
	输出: 4
	解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/
#include<bits/stdc++.h>
using namespace std;
/*O(nlogn)
int longestConsecutive(vector<int>& nums) {
	int longest = 1, len = 1;
	sort(nums.begin(), nums.end());
	for(auto it=nums.begin()+1; it != nums.end(); it++) {
		if(*it == *(it-1)+1)
			len++;
		else {
			if(len > longest)
				longest = len;
			len = 1;
		}
	}
    return longest;    
}
*/
/*
用C++写失败了，因为C++中没有HashSet一样牛逼的东西 
*/
int longestConsecutive(vector<int>& nums) {
    int maxn = 2048;
    bool exist[maxn] = {false};
    for (auto it=nums.begin(); it!=nums.end(); it++) 
        exist[*it+1024] = true;

    int longestStreak = 0;

    for (auto it=nums.begin(); it!=nums.end(); it++) {
        if (!exist[*it-1+1024]) {
            int currentNum = *it;
            int currentStreak = 1;

            while (exist[currentNum+1+1024]) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}


int main() {
	vector<int> vec = {100, 4, 200, 1, 3, 2};
	printf("%d", longestConsecutive(vec));
	return 0;
}
