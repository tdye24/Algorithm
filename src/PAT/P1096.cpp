#include<bits/stdc++.h>
using namespace std;
int N, temp;
int factor[15], num = 0; //13！>2^31 ,num标记factor数量 
int ans[15], ans_num = 0;
//因子中大于等于sqrt（n）的最多只有一个

bool isPrime(int n) {
	int sqrn = sqrt(n);
	for(int i=2; i<=sqrn; i++) {
		if(n%i==0)
			return false;
	}
	return true;
}

int main() {
	scanf("%d", &N);
	if(isPrime(N)) {
		printf("1\n%d\n", N);
		return 0;
	} 
	int sqrN = (int)sqrt(N);
	for(int i=2; i<=sqrN+1; i++) { //连乘的第一个数i:2->sqrN 
		temp = N;
		for(int j=i; j<=sqrN+1; j++) {
			if(temp%j == 0) {
				factor[num++] = j;
				temp /= j;
				if(temp == 1) {
					if(num <= ans_num) {
						num = 0;
						break;
					} else {
						ans_num = num;
						for(int k=0; k<num; k++) 
							ans[k] = factor[k];
						num = 0;
						break;
					}
				}
			} else {
				if(num <= ans_num) {
					num = 0;
					break;
				} else {
					ans_num = num;
					for(int k=0; k<num; k++) 
						ans[k] = factor[k];
					num = 0;
					break;
				}
			}
		}
	}
	printf("%d\n", ans_num);
	for(int i=0; i<ans_num; i++) 
		if(i == 0)
			printf("%d", ans[i]);
		else 
			printf("*%d", ans[i]);
	return 0; 
}
