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

bign multi(bign a, int b) { //高精度与低精度的乘法binn a×int b 
	bign c;
	int carry = 0; //carry是进位
	for(int i=0; i<a.len; i++) {
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0) { //和加法不一样，乘法的进位可能不止一位，因此用while 
		c.d[c.len++] = carry;
		carry /= 10;
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
	print(multi(a, b));
	return 0;
} 
