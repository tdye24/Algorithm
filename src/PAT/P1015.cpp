#include<bits/stdc++.h>
using namespace std;
int N, D;

int bin[20], num;
bool isPrime(int n) {
	if(n == 1)
		return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2; i<=sqr; i++) {
		if(n%i == 0)
			return false;
	}
	return true;
}


int main() {
	stack<int> st;
	int max, reverse;
	while(~scanf("%d", &N) && N>0) {
		scanf("%d", &D);
		int N_ = N;
		while(N>=D) {
			st.push(N%D);
			N /= D;
		}
		st.push(N);
		max = st.size();
		reverse = 0;
		for(int i=0; i<max; i++) {
			reverse += (int)(st.top()*pow(D, i));
			st.pop();
		}
			
		if(isPrime(N_) && isPrime(reverse))
			printf("Yes\n");
		else 
			printf("No\n");
		
	}
	
	
}
