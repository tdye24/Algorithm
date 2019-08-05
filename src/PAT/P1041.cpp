#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;
int arr[maxn];
int temp[maxn];
set<int> st;
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
		temp[i] = arr[i];
	}
	sort(temp, temp+n);
	for(int i=0; i<n-1; i++) {
		if(temp[i+1] == temp[i]) {
			st.insert(temp[i]);
		}
	}
	for(int i=0; i<n; i++) {
		if(st.find(arr[i]) == st.end()) {
			printf("%d\n", arr[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}
