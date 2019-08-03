#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1000050;
int m; //¶¥µãÊý 
vector<int> Adj[MAXV];
bool vis[MAXV];
void DFS(int u, int depth) {
	vis[u] = true;
	for(int i=0; i<Adj[u].size(); i++) {
		int v = Adj[u][i];
		if(vis[v] == false) {
			DFS(v, depth+1);
		}
	} 
}

int main() {
	int from, to, m = 0;
	for(int i=0; i<1000050; i++) {
		vis[i] = true;
	} 
	
	while(cin >> from >> to) {
		Adj[from].push_back(to);
		Adj[to].push_back(from);
		vis[from] = false;
		vis[to] = false;
		m = max(m, from);
		m = max(m, to);
	}
	int ans = 0;
	for(int u=0; u<=m; u++) {
		if(vis[u] == false) {
			DFS(u, 1);
			ans ++;
		}	
	}
	cout << ans;
	return 0;
} 
