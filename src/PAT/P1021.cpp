#include<bits/stdc++.h>
using namespace std;
const int MAXV = 10010;
vector<int> Adj[MAXV]; 
bool vis[MAXV] = {false};
int Ahighest = 0; //A节点最远距离 
set<int> s; 

void DFS(int u, int depth) {
	vis[u] = true;
	if(depth > Ahighest) {
		Ahighest = depth; 
		s.clear();
		s.insert(u);
	} else if(depth == Ahighest){
		s.insert(u);
	}
	for(int i=0; i<Adj[u].size(); i++) {
		int v = Adj[u][i];
		if(vis[v] == false) {
			DFS(v, depth+1);
		}
	}
}



int main() {
	int N;
	scanf("%d", &N); //顶点个数
	if (N == 1) {
		printf("1\n");
		return 0;
	}
	int K = 0; //连通分支数-DFS次数 
	int from, to;
	for(int i=0; i<N-1; i++) {
		scanf("%d%d", &from, &to);
		Adj[from].push_back(to);
		Adj[to].push_back(from);
	} 
	for(int u=1; u<=N; u++) {
		if(vis[u] == false) {
			K++;
			DFS(u, 0);
		}
	}
	if(K != 1) {
		printf("Error: %d components\n", K);
		return 0;
	}
	set<int>::iterator it = s.begin();
	int temp = *it;
	set<int> stemp = s;
	s.clear();
	fill(vis, vis+MAXV, false);
	Ahighest = 0;
	DFS(temp, 0);
	it = stemp.begin();
	for (; it != stemp.end(); it++) {
		s.insert(*it);
	}
	it = s.begin();
	for (; it != s.end(); it++) {
		printf("%d\n", *it);
	}
	return 0;
}
 
