#include<bits/stdc++.h>
//O(n2)
using namespace std;
int a[10005], f[10005];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) f[i] = 1;
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	int ans = 1;
	for(int i=2; i<=n; i++) {
		for(int j=1; j<i; j++) {
			if(a[j] < a[i])
				f[i] = max(f[i], f[j]+1);
		}
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
	return 0;
	
} 


