#include<bits/stdc++.h>
using namespace std;
const int maxn = 24;
struct bign {
	int d[maxn];
	int len;
	bign() {
		fill(d, d+maxn, 0);
		len = 0;
	}
};

bign change(string s) {
	bign a;
	for(int i=s.length()-1; i>=0; i--) {
		a.d[a.len++] = s[i] - '0';
	}
	return a;
}

bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for(int i=0; i<max(a.len, b.len); i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}

bign sub(bign a, bign b) {
	bign c;
	for(int i=0; i<max(a.len, b.len); i++) {
		if(a.d[i] < b.d[i]) {
			a.d[i+1]--;
			a.d[i] += 10;
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while(c.len >= 2 && c.d[c.len-1] == 0) {
		c.len--;
	}
	return c;
}

int compare(bign a, bign b) {
	if(a.len > b.len)	return 1;
	else if(a.len < b.len)	return -1;
	else {
		for(int i=a.len-1; i>=0; i--) {
			if(a.d[i] > b.d[i])	return 1;
			else if(a.d[i] < b.d[i]) return -1;
		}
		return 0;
	}
	
}

int main() {
	int T;
	string s1, s2, s3;
	cin >> T;
	bign a, b, ans, c;
	for(int i=1; i<=T; i++) {
		cin >> s1 >> s2 >> s3;
		bool fa = false, fb = false, fans = false, fc = false;
		if(s1[0] == '-') {
			a = change(s1.substr(1, s1.length()-1));
			fa = true;
		} else {
			a = change(s1);
		}
		if(s2[0] == '-') {
			b = change(s2.substr(1, s2.length()-1));
			fb = true;
		} else {
			b = change(s2);
		}
		if(s3[0] == '-') {
			c = change(s3.substr(1, s3.length()-1));
			fc = true;
		} else {
			c = change(s3);
		}	
		if(fa && fb) { //a<0, b<0
			fans = true;
			ans = add(a, b);
		} else if(fa && !fb) { //a<0, b>0
			if(compare(a, b) > 0) { // -7+5
				fans = true;
				ans = sub(a, b);
			} else if(compare(a, b) < 0) { //-5+7
				fans = false;
				ans =  sub(b, a);
			}
		} else if(!fa && fb) { //a>0, b<0 
			if(compare(a, b) > 0) { // 7-5
				fans = false;
				ans = sub(a, b);
			} else if(compare(a, b) < 0) { //5-7
				fans = true;
				ans = sub(b, a);
			}
		} else {
			fans = false;
			ans = add(a, b);
		}
		cout << "Case #" << i << ": ";
		if(!fans && fc) { //ans>0, c<0
			cout << "true" << endl;
		} else if(fans && !fc) { //ans<0, c>0
			cout << "false" << endl;
		} else if(fans && fc) { //ans<0, c<0 
			if(compare(ans, c) > 0) {
				cout << "false" << endl;
			} else {
				cout << "true" << endl;
			}
		} else { //ans>0, c>0
			if(compare(ans, c) <= 0) {
				cout << "false" << endl;
			} else {
				cout << "true" << endl;
			}			
		}
	}
	return 0;
}
