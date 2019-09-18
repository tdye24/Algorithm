/*
*PAT1081
*/ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll numerator, denominator, up = 0, down = 1;
ll gcd(ll a, ll b) {
	if(a < b)	swap(a, b);
	return !b ? a : gcd(b, a % b);
}
int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		scanf("%lld/%lld", &numerator, &denominator);
		up = up * denominator + numerator * down;
		down = down * denominator;
	}
	if(down < 0) {
		up = - up;
		down = - down;
	}
	
	if(up == 0)	down = 1;
	else {
		ll d = gcd(abs(up), abs(down));
		up /= d;
		down /= d;
	} 
	
	if(down == 1)	printf("%lld", up);
	else if(abs(up) > down)	printf("%d %d/%d", up/down, abs(up)%down, down);
	else	printf("%d/%d", up, down);
	return 0;
}
