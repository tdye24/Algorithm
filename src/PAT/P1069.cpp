#include<bits/stdc++.h>
using namespace std;
int n, s[4];
int main() {
	int left, right;
	scanf("%d", &n);
	left = n;
	int a, b, c, d;
	a = n/1000;
	b = (n%1000)/100;
	c = (n%100)/10;
	d = n%10;
	if(a==b&&b==c&&c==d)
		printf("%d - %d = 0000", n, n);
	else if(left == 6174)
		printf("7641 - 1467 = 6174\n");
	else {
		while(left != 6174) {
			
			a = left/1000;
			b = (left%1000)/100;
			c = (left%100)/10;
			d = left%10;
			
			if(a < b) 
				swap(a, b);
			if(b < c)
				swap(b, c);
			if(c < d)
				swap(c, d);
			if(a < b) 
				swap(a, b);
			if(b < c)
				swap(b, c);
			if(a < b) 
				swap(a, b);
			left = a*1000+b*100+c*10+d; 
			
			right = 0;
			right =	d*1000+c*100+b*10+a;
			printf("%04d - %04d = %04d\n", left, right, left-right);
			left = left - right;
		}
	}
}
