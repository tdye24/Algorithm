#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int father[N]; //存放父亲节点 
int num[N]; //记录每个节点是否作为每个集合的根节点 
int hobby[N]; 

void init(int n) {
	for(int i=1; i<=n; i++) {
		father[i] = i;
		num[i] = 0;
	}
}

int findFather(int x) {
	int a = x;
	while(x !=father[x]) {
		x = father[x];
	}
	
	//路径压缩
	while(a != father[a]) {
		father[a] = x;
		a = father[a];
	} 
	
	return x;
}

void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	
	if(faA != faB) {
		father[faA] = faB;
	}
}



bool cmp(int a, int b){
	return a>b;
}

int main() {
	int n;
	scanf("%d",&n);
	init(n);
	int k;
	for(int i=1; i<=n; i++) {
		scanf("%d:",&k);
		int temp = 0;
		for(int j=0; j<k; j++) {
			scanf("%d",&temp);
			if(hobby[temp]==0)
				hobby[temp]=i;
			Union(i, hobby[temp]);
		}
	}
	for(int i=1; i<=n; i++){
		num[findFather(i)]++;
	}
	
	sort(num+1,num+1+n,cmp);
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(num[i] != 0)
			ans++;
		else
			break;
	}
	printf("%d\n", ans);
	for(int i=1; i<=ans; i++){
		if(i == 1)
			printf("%d", num[i]);
		else
			printf(" %d", num[i]);
	}
	return 0;
}
