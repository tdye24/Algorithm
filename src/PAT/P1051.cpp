#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int arr[maxn];
int m, n, k;

void solve(int arr[]) {
	stack<int> st;
	int i = 0;
	int num = 1;
	while(i<n) {
		if(st.empty()) {
			st.push(num++);
		}
		while(st.size() <= m && st.top() != arr[i]) {
			st.push(num++);
		}
		if(st.size() > m) {
			printf("NO\n");
			return;		
		}
		if(st.top() == arr[i]) {
			st.pop();
			i++;
		}	
	}
	if(i==n && st.empty())
		printf("YES\n");		
}

int main() {
	scanf("%d%d%d", &m, &n, &k);
	for(int i=0; i<k; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", &arr[j]); 
		}
		solve(arr);
	}
	return 0;
}
