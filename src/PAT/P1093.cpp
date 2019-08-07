#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int leftNumP[maxn];
int rightNumT[maxn]; 
int main() {
	string s;
	cin >> s;
	int n = s.length();
	if(s[0] == 'P')	
		leftNumP[0] = 1;
	for(int i=1; i<n; i++) {
		if(s[i] == 'P')
			leftNumP[i] = leftNumP[i-1] + 1;
		else
			leftNumP[i] = leftNumP[i-1];
	}
	int ans = 0;
	if(s[n-1] == 'T')	
		rightNumT[n-1] = 1;
	for(int i=n-2; i>=0; i--) {
		if(s[i] == 'T')
			rightNumT[i] = rightNumT[i+1] + 1;
		else if(s[i] == 'A') {
			rightNumT[i] = rightNumT[i+1];
			ans = (ans+leftNumP[i]*rightNumT[i])%1000000007;
		} else
			rightNumT[i] = rightNumT[i+1];		
	}
	printf("%d\n", ans);
} 
