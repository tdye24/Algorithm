#include<bits/stdc++.h>
using namespace std;
const int maxn = 24;
int N;
struct Node {
	string data;
	int left;
	int right;
} nodes[maxn];

bool isRoot[maxn] = {false};

int findRoot() {
	for(int i=1; i<=N; i++) {
		if(!isRoot[i])
			return i;
	}
	return -1;
}

void Inorder(int root) {
	if((nodes[root].left != -1 || nodes[root].right != -1) && root != findRoot()) {
		cout << "(";
	}
	if(nodes[root].left != -1) 
		Inorder(nodes[root].left);
	cout << nodes[root].data;
	if(nodes[root].right != -1) 
		Inorder(nodes[root].right);
	if((nodes[root].left != -1 || nodes[root].right != -1) && root != findRoot()) {
		cout << ")";
	}
	return;
}

int main() {
	scanf("%d", &N);
	string data;
	int left, right;
	for(int i=1; i<=N; i++) {
		cin >> data >> left >> right;
		isRoot[left] = true;
		isRoot[right] = true;
		nodes[i].data = data;
		nodes[i].left = left;
		nodes[i].right = right;
	}
	Inorder(findRoot());
	return 0;
}
