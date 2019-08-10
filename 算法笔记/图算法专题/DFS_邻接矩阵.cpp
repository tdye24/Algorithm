#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int INF = 1000000000;
int n;
int G[maxn][maxn];
bool vis[maxn] = {false};
void DFS(int u, int depth) {
	vis[u] = true;
	for(int v=0; v<n; v++) {
		if(vis[v] == false && G[u][v] != INF) {
			DFS(v, depth+1);
		}
	}
}

void DFSTravel() {
	int count = 0;
	for(int u=0; u<n; u++) {
		if(vis[u] == false) {
			DFS(u, 1);
		}
	}
}
int main() {
	
}
