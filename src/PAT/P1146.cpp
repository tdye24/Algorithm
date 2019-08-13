#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int INF = 2;
int G[maxn][maxn];
int G_[maxn][maxn];
int N, M, K;
int ans[110], num = 0;

void query(int G[][maxn], int option[], int indice) {
	for(int i=0; i<N; i++) {
		for(int j=1; j<=N; j++) {
			if(G[j][option[i]] != 0) {
				ans[num++] = indice;
				return;
			}
		}
		for(int j=1; j<=N; j++) {
			G[option[i]][j] = 0;
		}
	} 
	return;
}

int main() {
	scanf("%d%d", &N, &M);
	int u, v;
	for(int i=0; i<M; i++) {
		scanf("%d%d", &u, &v);
		G[u][v] = 1;
	}
	scanf("%d", &K);
	int option[N];
	for(int i=0; i<K; i++) {
		for(int j=0; j<N; j++)
			scanf("%d", &option[j]);
		for(int p=0; p<maxn; p++) {
			for(int q=0; q<maxn; q++) {
				G_[p][q] = G[p][q];
			}
		}
		query(G_, option, i);
	}
	for(int i=0; i<num; i++) {
		if(i == 0)
			printf("%d", ans[i]);
		else
			printf(" %d", ans[i]);
	}
	return 0;
}
