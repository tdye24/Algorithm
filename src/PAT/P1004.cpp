#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m, height;
struct Node {
	int layer; //¼ÇÂ¼²ãºÅ 
	vector<int> child;
} node[maxn];
int leaves[maxn];
void LevelOrder(int root) {
	queue<int> Q;
	Q.push(root);
	node[root].layer = 0;
	while(!Q.empty()) {
		int front = Q.front();
		if(node[front].child.size() == 0) 
			leaves[node[front].layer] += 1;
		Q.pop();
		for(int i=0; i<node[front].child.size(); i++) {
			int child = node[front].child[i];
			node[child].layer = node[front].layer + 1;
			height = node[child].layer;
			Q.push(child);
		}
	}
}

int main() {
	scanf("%d", &n);
	if(n == 0)
		return 0;
	scanf("%d", &m); 
	int id, k, child;
	for(int i=0; i<m; i++) {
		scanf("%d%d", &id, &k);
		for(int j=0; j<k; j++) {
			scanf("%d", &child);
			node[id].child.push_back(child);
		}
	}
	
	LevelOrder(1);
	
	for(int i=0; i<=height; i++) {
		if(i==0) 
			printf("%d", leaves[i]);
		else 
			printf(" %d", leaves[i]);
	}
}
