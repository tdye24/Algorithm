#include<bits/stdc++.h>
using namespace std;
const int maxn = 101;
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

int main() {
	Find_Prime();
	for(int i=0; i<pNum; i++) {
		printf("%d ", prime[i]);
	}
	return 0;
}
