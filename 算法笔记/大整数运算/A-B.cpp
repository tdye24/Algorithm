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

bign sub(bign a, bign b) { //高精度a-b 
	bign c;
	for(int i=0; i<max(a.len, b.len); i++) {
		if(a.d[i] < b.d[i]) { //如果不够减
			a.d[i+1]--; //向高位借位
			a.d[i]+=10; //当前位加10 
		}
		c.d[c.len++] = a.d[i] - b.d[i]; //减法结果为当前位结果 
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
	string s1, s2;
	cin >> s1 >> s2;
	bign a = change(s1);
	bign b = change(s2);
	print(sub(a, b));
	return 0;
} 
