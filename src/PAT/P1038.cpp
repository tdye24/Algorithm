#include<bits/stdc++.h> 
using namespace std;
const int maxn = 10010;
string arr[maxn];
int n;

int prefix[12];

bool cmp(string s1, string s2) {
	return s1+s2<s2+s1;
}

int main() {
	cin >> n;
	int pre;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n, cmp);
	string s;
	for(int i=0; i<n; i++)
		s += arr[i];
	while(s.length()>0 && s[0] == '0')
		s.erase(s.begin());
	if(s.length() == 0) {
		cout << 0;
		return 0;
	}
		
	cout << s << endl;
		
	return 0;
}
