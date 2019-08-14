#include<bits/stdc++.h>
using namespace std;
const int maxn = 12;
int N, level_num = 0, inorder_num = 0;
struct Node {
	int left, right;
} nodes[maxn];

bool not_root[maxn] = {false};

void LevelOrder(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		level_num++;
		int front = q.front();
		if(level_num == 1)
			printf("%d", front);
		else
			printf(" %d", front);
		q.pop();
		if(nodes[front].left != -1)
			q.push(nodes[front].left);
		if(nodes[front].right != -1)
			q.push(nodes[front].right);
	}
	
}

void InOrder(int root) {
	if(nodes[root].left != -1)
		InOrder(nodes[root].left);
	inorder_num++;
	if(inorder_num == 1)
		printf("%d", root);
	else
		printf(" %d", root);
	if(nodes[root].right != -1)
		InOrder(nodes[root].right);
}

int main() {
	scanf("%d", &N);
	getchar();
	char right, left;
	for(int i=0; i<N; i++) {
		scanf("%c %c", &right, &left);
		getchar();
		if(right != '-') {
			nodes[i].right = right - '0';
			not_root[right-'0'] = true;
		}	
		else
			nodes[i].right = -1;
		if(left != '-') {
			nodes[i].left = left - '0';
			not_root[left-'0'] = true;
		}
		else
			nodes[i].left = -1;
	}
	int root = -1;
	for(int i=0; i<N; i++) {
		if(!not_root[i]) {
			root = i;
			break;
		}
			
	}
	LevelOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	return 0;
} 
