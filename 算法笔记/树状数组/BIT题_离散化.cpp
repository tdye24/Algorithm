#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
#define lowbit(i) ((i)&(-i)) 
struct Node {
	int val; //序列元素的值 
	int pos; //原始序号 
} temp[maxn]; //temp数组临时存放输入数据

int A[maxn]; //离散后的原始数组
int c[maxn]; //树状数组

void update(int x, int v) {
	for(int i=x; i<maxn; i+=lowbit(i)) {
		c[i] += v;
	}
} 

void getSum(int x) {
	for(int i=x; i>0; i-=lowbit(i)) {
		sum += c[i];
	}
	return sum;
}

bool cmp(Node a, Node b) {
	return a.val < b.val;
}

int main() {
	int n;
	scanf("%d", &n);
	memset(c, 0, sizeof(c));  //树状数组初值为0 
	
	for(int i=0; i<n; i++) {
		scanf("%d", &temp[i].val);  //输入序列元素 
		temp[i].pos = i; //原始序号 
	}
	
	//离散化
	sort(temp, temp+n, cmp);
	
	for(int i=0; i<n; i++) { 
		if(i == 0 || temp[i].val != temp[i-1].val) { //与上一个元素值不同时，赋值为元素个数 
			A[temp[i].pos] = i+1;
		} else {  //与上一个值相同时，直接继承 
			A[temp[i].pos] = A[temp[i-1].pos];
		}
	} 
	
	//正式进入更新求和操作 
	for(int i=0; i<n; i++) {
		update(A[i], 1);
		printf("%d\n", getSum(A[i]-1));
	} 
	
	return 0;
	
}

