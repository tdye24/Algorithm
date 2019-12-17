/*实现int sqrt(int x)函数。
计算并返回x的平方根，其中x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
示例 1:
输入: 4
输出: 2
示例 2:
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
由于返回类型是整数，小数部分将被舍去。
*/
#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
	if(x == 0)
		return 0; 
    double pre = x, current = x;
	while(true) {
		current = (current+x/current)/2;
		if(abs(current-pre) < 1e-6)
			return int(current);
		pre = current;
	}    
} 

int main() {
	int a = 8;
	printf("%d", mySqrt(a));
	return 0;
}
