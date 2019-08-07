#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int INF = 1000000000;
int n, origin[maxn], leftMax[maxn], rightMin, ans[maxn];
int main() {
	scanf("%d", &n);
	int data;
	for(int i=0; i<n; i++) {
		scanf("%d", &data);
		origin[i] = data;
		if(i>0) {
			if(origin[i-1] > leftMax[i-1]) 
				leftMax[i] = origin[i-1];
			else
				leftMax[i] = leftMax[i-1];
		} else
			leftMax[i] = 0;
	}
	int index = 0;
	for(int i=n-1; i>=0; i--) {
		if(i <n-1) {
			if(origin[i+1] < rightMin)
				rightMin = origin[i+1];
		} else
			rightMin = INF;
		if(origin[i] > leftMax[i] && origin[i] < rightMin) 
			ans[index++] = origin[i];	
	} 
	sort(ans, ans+index);
	printf("%d\n", index);
	for(int i=0; i<index; i++) {
		if(i==0)
			printf("%d", ans[i]);
		else 
			printf(" %d", ans[i]);
	}
	if(index == 0) //格式错误测试点，即使pivot个数为0，也要换行 
		printf("\n");
}
