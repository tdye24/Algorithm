#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int coins[maxn]; //下标为面值，存放该面值的数量
int N, M, coin, max_value, min_value = 1010;
int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++) {
		cin >> coin;
		max_value = max(max_value, coin); 
		min_value = min(min_value, coin);
		coins[coin]++;
	}
	for(int i=min_value; i<=M/2; i++) { //此处i<=M/2而不是max_value/2 
		if(coins[i] > 0) {
			coins[i]--;
			if(coins[M-i] > 0) {
				cout << i << " " << M-i << endl;
				return 0;
			}
			coins[i]++; //如果凑不出M，放回[i] 
		}
	} 
	cout << "No Solution" << endl;
	return 0;
} 
