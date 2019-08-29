#include<bits/stdc++.h>
using namespace std;
struct Node {
	int left, right;
	Node(int i, int j) {
		left = i;
		right = j;
	}
};
const int maxn = 100010;
const int INF = 0x7fffffff;
int arr[maxn];
int sum[maxn];
int N, M;
int lower_bound(int left, int right) {
	int mid, base = left-1;
	while(left < right) {
		mid = (left+right)/2;
		if(sum[mid]-sum[base] >= M) 
			right = mid;
		else 
			left = mid + 1;	
	}
	return left;
}
int main() {
	queue<Node> q;
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
	}
	for(int i=1; i<=N; i++) {
		sum[i] = sum[i-1] + arr[i];
	}
	
	int MIN = INF;
	for(int i=1; i<=N; i++) { 
		int j = lower_bound(i, N+1);
		if(sum[j]-sum[i-1]-M >= 0) {
			if(sum[j]-sum[i-1]-M < MIN) {
				while(!q.empty()) 
					q.pop();
				MIN = sum[j]-sum[i-1]-M;
				q.push(Node(i, j)); 
			} else if(sum[j]-sum[i-1]-M == MIN) {
				q.push(Node(i, j)); 
			} 	
		}
	}
	while(!q.empty()) {
		printf("%d-%d\n", q.front().left, q.front().right);
		q.pop();
	}
	return 0;
} 
