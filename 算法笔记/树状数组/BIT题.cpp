/*统计序列中在元素左边比该元素小的元素个数 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
#define lowbit(i) ((i) & (-i))
int c[maxn]; //树状数组
//update函数将第x个整数加上v 
void update(int x, int v) {
	for(int i=x; i<maxn; i+=lowbit(i)) {  //i<maxn或者i<=n都可以 
		c[i] += v;  //让c[i]加上c，然后让c[i+lowbit(i)]加上v 
	}
} 
//getSum函数返回前x个整数之和
int getSum(int x) {
	int sum = 0;
	for(int i=x; i>0; i-=lowbit(i)) {  //注意是i>0而不是i>=0 
		sum += c[i];
	}  //累计c[i],然后把问题缩小为SUM(1, i-lowbit(i)) 
	return sum;  //返回和 
} 
int main() {
	int n, x;
	scanf("%d", &n);
	memset(c, 0, sizeof(c)); //树状数组初值为0
	for(int i=0; i<n; i++) {
		scanf("%d", &x); //输入序列元素
		update(x, 1);  //x的出现次数加1
		printf("%d\n", getSum(x-1)); 
	} 
	return 0;
} 
