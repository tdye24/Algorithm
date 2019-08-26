#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int arr[maxn], N, data, k;
int main() {
	memset(arr, 0x3f, sizeof(arr)); 
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &data);
		if(data > 0) {
			arr[k++] = data;
		}
		
	}
	sort(arr, arr+k);
	for(int i=1; i<k; i++) {
		if(arr[i] - arr[i-1] > 1) {
			printf("%d", arr[i-1]+1);
			return 0;
		}		
	}
	printf("%d", arr[k-1]+1);
	return 0;
} 
