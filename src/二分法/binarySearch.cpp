#include<bits/stdc++.h>
using namespace std;

int binarySearch(int list[], int left, int right, int x) {
	int mid;	//mid为left和right的中点
	while(left <= right) {	//如果left>right就没办法形成闭区间了
		mid = (left + right) / 2;	//取中点
		if(list[mid] == x)	return mid;
		else if(list[mid] > x) {	//中间的数大于x 
			right = right - 1;	//往左子区间[left, right-1]查找 
		} else {	//中间的数小于x 
			left = mid + 1;		//往右子区间[mid+1, right]查找 
		}
	} 
	return -1;	//查找失败，返回-1 
}

int main() {
	const int n = 15;
	int my_list[n] = {2, 29, 33, 42, 59, 67, 87, 92, 100, 210, 282, 381, 467, 578, 666};
	printf("The index is %d.", binarySearch(my_list, 0, n-1, 282));
	return 0;
} 
