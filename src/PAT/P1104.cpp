#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
int main() {
	double data;
	double ans = 0.0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++) { //第几个数，输入时即处理 
		scanf("%lf", &data);
		ans += data*i*(N+1-i); //ans += i*(N+1-i)*data;最后两个测试点错误，原因i*(N+1-i)越界 
	} 
	printf("%.2lf\n", ans);
	return 0;
}
