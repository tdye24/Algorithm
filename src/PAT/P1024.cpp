#include<bits/stdc++.h>
using namespace std;

bool isPalin(string s) {
	for(int i=0, j=s.size()-1; i<=j; i++, j--) {
		if(s[i] != s[j])
			return false; 
	}
	return true;
} 

string add(string s1) {
	string ans = "";
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	int carry = 0;
	for(int i=s1.size()-1; i>=0; i--) {
		int t1 = s1[i]-'0';
		int t2 = s2[i]-'0';
		int current = (t1+t2+carry)%10;
		carry = (t1+t2+carry)/10;
		ans = to_string(current) + ans;
	}
	if(carry >= 1)
		ans = "1" + ans;
	return ans;
}

int main() {
	string N;
	int K, i=0;
	cin >> N >> K;
	while(!isPalin(N)) {
		N = add(N);
		i++;
		if(i>=K)
			break;
	}
	cout << N << endl;
	cout << i << endl;
} 
