#include<stdio.h>
const int maxn = 8010;
int main() {
	int n;
	int pre[maxn], ans[maxn], num[maxn];
	scanf("%d", &n);
	pre[1] = 0;
	for(int i=1; i<=n; i++) {
		num[i] = i;
	}
	
	for(int i=2; i<=n; i++) {
		scanf("%d", &pre[i]);
	}
	
	for(int i=n; i>=1; i--) {
		int k = 0;
		for(int j=1; j<=n; j++) {
			if(num[j]!=-1) {
				k++;
				if(k == pre[i]+1) {
					ans[i] = num[j];
					num[j] = -1;
					break;
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++) 
		printf("%d\n", ans[i]);
	
	return 0;
} 
