#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int prime[maxn], pNum = 0;
bool p[maxn] = {false};

void Find_Prime() {
	for(int i=2; i<maxn; i++) {
		if(p[i] == false) {
			prime[pNum++] = i;
			for(int j=i+i; j<maxn; j += i) {
				p[j] = true;
			}
		}
	}
}

struct factor {
	int x, cnt; //x为质因子，cnt为其个数 
} fac[10];

int main() {
	Find_Prime();
	int n, num = 0;
	scanf("%d", &n);
	if(n == 1) {
		printf("1=1");
		return 0;
	}
	printf("%d=", n);
	int sqr = (int)sqrt(1.0*n);
	for(int i=0; i<pNum&&prime[i] <= sqr; i++) {
		if(n % prime[i] == 0) {
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			while(n % prime[i] == 0) {
				fac[num].cnt ++;
				n /= prime[i];
			}
			num++;
		}
		if(n == 1)
			break;
	}
	
	if(n != 1) {
		fac[num].x = n;
		fac[num++].cnt = 1;
	}	
	
	for(int i=0; i<num; i++) {
		if(i>0) 
			printf("*");
		printf("%d", fac[i].x);
		if(fac[i].cnt > 1) 
			printf("^%d", fac[i].cnt);
	}
	return 0;
	
}
