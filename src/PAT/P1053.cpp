#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct Node {
	int data;
	vector<int> child;
} node[maxn];

bool cmp(int a, int b) {
	return node[a].data > node[b].data; 
}
int n, m, S;
int path[maxn]; //记录路径

//当前访问节点为index,numNode为当前路径path上的节点个数 
//sum为当前的节点点权和 
void DFS(int index, int numNode, int sum) {
	if(sum > S) 
		return;
	if(sum == S) {
		if(node[index].child.size() != 0)
			return;
		for(int i=0; i<numNode; i++) {
			printf("%d", node[path[i]].data);
			if(i<numNode-1)
				printf(" ");
			else
				printf("\n");
		}
		return;
	}
	//sum<S
	for(int i=0; i<node[index].child.size(); i++) {
		int child = node[index].child[i];
		path[numNode] = child;
		DFS(child, numNode+1, sum+node[child].data);
	}
} 
int main() {
	scanf("%d%d%d", &n, &m, &S);
	for(int i=0; i<n; i++) {
		scanf("%d", &node[i].data);
	}
	int id, k, child;
	for(int i=0; i<m; i++) {
		scanf("%d%d", &id, &k);
		for(int j=0; j<k; j++) {
			scanf("%d", &child);
			node[id].child.push_back(child);
		}
		sort(node[id].child.begin(), node[id].child.end(), cmp);
	}
	path[0] = 0;
	DFS(0, 1, node[0].data);
	return 0;
}
