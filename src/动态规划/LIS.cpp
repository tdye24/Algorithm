#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int arr[maxn];
int n;
int LIS() {
	int len = 1;
	int d[maxn];
	d[1] = arr[1]; //初始化 
	for(int i=2; i<=n; i++) { //O(n) 
		if(arr[i]>d[len]) {
			d[++len] = arr[i]; //符合递增的要求，加入 
		} else { //替换 
			int j = lower_bound(d+1, d+1+len, arr[i]) - d; //O(logn) 
			d[j] = arr[i];
		}
	}
	return len; 
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d\n", LIS());
	return 0;
} 
