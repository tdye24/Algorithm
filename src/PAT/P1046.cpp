#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int arr[maxn], N, M, clk[maxn], anticlk[maxn];
int main() {
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> arr[i];
	clk[1] = 0;
	for(int i=2; i<=N; i++) {
		clk[i] = clk[i-1] + arr[i-1];
	}
	anticlk[1] = 0;
	anticlk[N] = arr[N];
	for(int i=N; i>=2; i--) {
		anticlk[i] = anticlk[i+1] + arr[i];
	}
	cin >> M;
	int a, b;
	for(int i=0; i<M; i++) {
		cin >> a >> b;
		if(a > b) 
			swap(a, b);
		printf("%d\n", min(clk[b]-clk[a], clk[a]+anticlk[b]));
	}
	return 0;
}
