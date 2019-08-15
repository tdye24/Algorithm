#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct Node {
	int generation;
	vector<int> children; 
} nodes[maxn];
int N, M; 

int gen[maxn] = {0}; //Í³¼Æevery generation members 

void BFS(int root) {
	queue<int> q;
	q.push(root);
	nodes[root].generation = 1;
	while(!q.empty()) {
		int front = q.front();
		gen[nodes[front].generation] += 1;
		q.pop(); 
		for(int i=0; i<nodes[front].children.size(); i++) {
			int child = nodes[front].children[i];
			nodes[child].generation = nodes[front].generation + 1;
			q.push(child); 
		}
		
	}
}

int main() {
	scanf("%d%d", &N, &M);
	int k = 0, parent, child;
	for(int i=0; i<M; i++) {
		scanf("%d%d", &parent, &k);
		for(int j=0; j<k; j++) {
			scanf("%d", &child);
			nodes[parent].children.push_back(child);
		}
	}
	BFS(1);
	int mx = 0, mi = 0;
	for(int i=0; i<=N; i++) {
		if(gen[i] > mx) {
			mx = gen[i];
			mi = i;
		}
	} 
	printf("%d %d\n", mx, mi);
	return 0;
} 
