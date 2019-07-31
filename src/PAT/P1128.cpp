#include<bits/stdc++.h> 
using namespace std;

int arr[1010];

bool isValid(int arr[],int N) {
	for(int i=2; i<=N; i++) {
		for(int j=1; j<i; j++) {
			if(arr[i] == arr[j])
				return false;
			if(abs(i-j) == abs(arr[i] - arr[j]))
				return false;
		}
	}
	return true;
}

int main() {
	int K, N;
	scanf("%d", &K);
	for(int i=1; i<=K; i++) {
		scanf("%d", &N);
		for(int j=1; j<=N; j++) {
			scanf("%d", &arr[j]);
		}
		if(isValid(arr, N))
			printf("YES\n");
		else
			printf("NO\n");
	}	
	return 0;
}

