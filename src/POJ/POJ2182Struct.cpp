#include<stdio.h>
using namespace std;
const int maxn = 10000;
struct Node {
	int l, r, len;
} tree[4*maxn];

int pre[maxn], ans[maxn];

void BuildTree(int left, int right, int u) {
	tree[u].l = left;
	tree[u].r = right;
	tree[u].len = right - left + 1;
	if(left == right)
		return;
	BuildTree(left, (left+right)>>1, u<<1);
	BuildTree(((left+right)>>1)+1, right, (u<<1)+1);
} 

int query(int u, int num) { //查询+维护，所求值为当前区间中左起第num个元素 
	tree[u].len --;
	if(tree[u].l == tree[u].r)
		return tree[u].l;
	if(tree[u<<1].len < num) 
		return query((u<<1)+1, num-tree[u<<1].len);
	if(tree[u<<1].len >= num)
		return query(u<<1, num);
}

int main() {
	int n;
	scanf("%d", &n);
	pre[1] = 0;
	for(int i=2; i<=n; i++) 
		scanf("%d", &pre[i]);
	BuildTree(1, n, 1);
	
	for(int i=n; i>=1; i--) 
		ans[i] = query(1, pre[i]+1);
	
	for(int i=1; i<=n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
