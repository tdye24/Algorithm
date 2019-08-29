/*
*PAT 1085
*/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int N, p;
int arr[maxn];
int upper_bound(int left, int right, long long x) {
	int mid;
	while(left < right) {
		mid = (left+right)/2;
		if(arr[mid] > x) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	scanf("%d%d", &N, &p);
	int len_max = 0;
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+N);
	for(int i=0; i<N; i++) {
		int j = upper_bound(i, N, (long long)p*arr[i]);
		len_max = max(len_max, j-i);
	}
	printf("%d\n", len_max);
	return 0;
} 
