#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int INF = 1000000000;
int n, m, k;
int G[maxn][maxn];
bool vis[maxn] = {false};
void DFS(int u, int depth) {
	vis[u] = true;
	for(int v=1; v<=n; v++) {
		if(vis[v] == false && G[u][v] != INF) {
			DFS(v, depth+1);
		}
	}
}

void DFSTravel(int G[][maxn], int x) {
	int row[maxn];
	int colum[maxn];
	for(int i=1; i<=n; i++) {
		row[i] = G[x][i];
	}
	for(int i=1; i<=n; i++) {
		colum[i] = G[i][x];
	}
	for(int i=1; i<=n; i++) {
		G[x][i] = G[i][x] = INF;
		
	}
	int count = 0;
	for(int u=1; u<=n; u++) {
		if(vis[u] == false) {
			DFS(u, 1);
			count++;
		}
		
	}
	printf("%d\n", count-2);
	for(int i=1; i<=n; i++) {
		G[x][i] = row[i];
	}
	for(int i=1; i<=n; i++) {
		G[i][x] = colum[i];
	}
	for(int i=1; i<=n; i++) {
		vis[i] = false;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	int a, b;
	fill(G[0], G[0]+maxn*maxn, INF); 
	
	for(int i=0; i<m; i++) {
		scanf("%d%d", &a, &b);
		G[a][b] = G[b][a] = 1;
	}
	
	
	int x;
	
	for(int i=0; i<k; i++) {
		scanf("%d", &x);
		DFSTravel(G, x);
	}
}
