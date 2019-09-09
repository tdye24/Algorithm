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

bign divide(bign a, int b, int& r) { //高精度与低精度除法bign a ÷int b 
	bign c;
	c.len = a.len; //被除数的每一位和商的每一位是一一对应的，因此先令长度相等 
	for(int i=a.len-1; i>=0; i--) { //从高位开始 
		r = r * 10 + a.d[i]; //和上一位遗留的余数组合
		if(r < b)	c.d[i] = 0; //不够除，该位为0
		else { //够除 
			c.d[i] = r / b; //商
			r = r % b; 
		} 
	}
	while(c.len >= 2 && c.d[c.len-1] == 0) {
		c.len--; //去除高位的0，同时至少保留一位最低位 
	} 
	return c;
}

void print(bign a) {
	for(int i=a.len-1; i>=0; i--) {
		printf("%d", a.d[i]);
	}
}

int main() {
	string s1;
	int b;
	cin >> s1 >> b;
	bign a = change(s1);
	int r = 0;
	print(divide(a, b, r));
	return 0;
} 
