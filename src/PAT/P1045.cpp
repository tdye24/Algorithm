#include<bits/stdc++.h>
//PAT1045 最长不下降子序列 
using namespace std;
const int maxn = 10010;
int N, M, L, k; 
int id[210], arr[maxn], dp[maxn];

int LIS() {
	int d[maxn];
	int len = 1;
	d[1] = arr[1];
	for(int i=2; i<=k; i++) { //删除4之后元素arr中元素个数小于L 
		if(arr[i]>=d[len]) {
			d[++len] = arr[i];
		} else {
			int j = upper_bound(d+1, d+1+len, arr[i]) - d;
			d[j] = arr[i];
		}
	} 
	return len;
}

int main() {
	int data, x;
	scanf("%d%d", &N, &M);
	for(int i=1; i<=M; i++) {
		scanf("%d", &x);
		id[x] = i;
	}
	scanf("%d", &L);
	for(int i=1; i<=L; i++) {
		scanf("%d", &data);
		if(id[data] != 0) 
			arr[++k] = id[data];
	}
	printf("%d\n", LIS());
}
