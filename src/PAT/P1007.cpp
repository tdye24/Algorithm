#include<stdio.h>
#define MAX 10001
int a[MAX];
int N;
int besti;
int bestj; 
int solve() {
	int sum = -1;
	for(int i=0; i<N; i++) {
		int thissum = 0;
		for(int j=i; j<N; j++) {
			thissum += a[j];
			if(thissum > sum) {
				sum = thissum;
				besti = i;
				bestj = j;
			} 
		}
	}
	return sum;
}
int main() {
	scanf("%d", &N);
	besti = 0;
	bestj = N-1;
	for(int i=0; i<N; i++) {
		scanf("%d", &a[i]);
	}
	int sum = solve();
	if(sum<0)
		sum = 0;
	printf("%d %d %d\n", sum, a[besti], a[bestj]);
} 
/*比较坑的数据
1 
-5

4
-1 0 0 0*/
