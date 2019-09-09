#include<bits/stdc++.h>
using namespace std;
struct bign {
	int d[1000];
	int len;
	bign() {
		fill(d, d+1000, 0);
		len = 0;
	}
};

bign change(string str) { //将整数转化为bign 
	bign a;
	a.len = str.length();
	for(int i=0; i<a.len; i++) {
		a.d[i] = str[a.len-1-i] - '0'; //倒序放置，方便计算 
	}
	return a; 
}

bign add(bign a, bign b) { //高精度a+b 
	bign c;
	int carry = 0; //carry是进位
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

void print(bign a) {
	for(int i=a.len-1; i>=0; i--) {
		printf("%d", a.d[i]);
	}
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	bign a = change(s1);
	bign b = change(s2);
	print(add(a, b));
	return 0;
} 
