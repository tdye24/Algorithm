#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1010;
int n; //¶¥µãÊý 
vector<int> Adj[MAXV];
bool vis[MAXV] = {false};
void DFS(int u, int depth) {
	vis[u] = true;
	for(int i=0; i<Adj[u].size(); i++) {
		int v = Adj[u][i];
		if(vis[v] == false) {
			DFS(v, depth+1);
		}
	} 
}

void DFSTravel() {
	for(int u=0; u<n; u++) {
		if(vis[u] == false) {
			DFS(u, 1);
		}
	}
} 

int main() {
	
} 
