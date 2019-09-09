#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int INF = 1e9;
int G[maxn][maxn];
int d[maxn];
bool vis[maxn] = {false};
int v, e, a, b, c;
void dijkstra(vector<int> op) {
	int source = op[0];
	d[source] = 0;
	for(int k=0; k<v; k++) {
		source = op[k];
		vector<int> temp;
		int maxl = INF;
		for(int i=1; i<=v; i++) {
			if(vis[i] == false && d[i] < maxl) {
				maxl = d[i];
			}
		}
		for(int i=1; i<=v; i++) {
			if(vis[i] == false && d[i] == maxl) {
				temp.push_back(i);
			}
		}
		bool flag = false;
		for(int i=0; i<temp.size(); i++) {
			if(source == temp[i]) {
				flag = true;
				vis[source] = true;
				for(int s=1; s<=v; s++) {
					if(vis[s] == false && G[source][s] != INF) {
						if(d[source] + G[source][s] < d[s]) {
							d[s] = d[source] + G[source][s];
						}
					}
				}
				break;
			}
		}
		if(!flag) {
			printf("No\n");
			return;
		}	
	}	
	printf("Yes\n");
	return;
}

int main() {
	cin >> v >> e;
	fill(G[0], G[0]+maxn*maxn, INF);
	fill(d, d+maxn, INF);
	for(int i=0; i<e; i++) {
		cin >> a >> b >> c;
		G[a][b] = c;
		G[b][a] = c;
	}
	int k, data;
	cin >> k;
	vector<int> op;
	for(int i=0; i<k; i++) {
		for(int j=0; j<v; j++) {
			cin >> data;
			op.push_back(data);
		}
		dijkstra(op);
		op.clear();
		fill(vis, vis+maxn, false);
		fill(d, d+maxn, INF);
	}
	return 0;
}