#include<bits/stdc++.h>
using namespace std;
const int MAXV = 510; //最大顶点数
const int INF = 1000000000; //设INF为一个很大的数 

int n, m, st, ed, G[MAXV][MAXV]; //n为顶点数，MAXV为最大顶点数
int d[MAXV]; //起点到达各点的最短路径长度
bool vis[MAXV] = {false}; //标记数组，vis[i] = true表示已访问。初值均为false
int cost[MAXV][MAXV]; //cost[u][v]表示u->v的花费
int c[MAXV]; //令从起点s到达顶点u的最少花费为c[u]，初始化时只有c[s]=0、其余c[u]均为INF 
int pre[MAXV];

void Dijkstra(int s) { //s为起点 
	fill(d, d+MAXV, INF); //fill函数将整个d数组赋值为INF（慎用memset）
	fill(c, c+MAXV, INF);
	for(int i=0; i<n; i++)
		pre[i] = i;
	d[s] = 0;
	c[s] = 0;
	for(int i=0; i<n; i++) { //循环n次
		int u = -1, MIN = INF; //u使d[u]最小，MIN存放该最小的d[u]
		for(int j=0; j<n; j++) { //找到未访问的顶点中d[]最小的
			if(vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			} 			
		} 
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
		if(u == -1)
			return;
		vis[u] = true; //标记u为已访问
		for(int v=0; v<n; v++) {
			//如果v未访问 && u能到达v && 以u为中介可以使d[v]更优
			if(vis[v] == false && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) { //以u为中介可以使d[v]更优 
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				} else if(d[u] + G[u][v] == d[v]) { //最短距离相同时看能否使c[v]更优 
					if(c[u] + cost[u][v] < c[v]) {
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}	
				} 
			} 

		} 
	} 
} 

void DFS(int v) { //s为起点编号，v为当前访问的顶点编号（从终点开始递归） 
	if(v == st) { //如果当前已经到达起点s，则输出起点并返回
		printf("%d ", v);
		return; 
	} 
	DFS(pre[v]); //递归访问v的前驱顶点pre[v]
	printf("%d ", v); 
} 

int main() {
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	int u, v;
	fill(G[0], G[0]+MAXV*MAXV, INF); //初始化图G
	//fill(cost[0], cost[0]+MAXV*MAXV, INF); 
	for(int i=0; i<m; i++) {
		scanf("%d%d", &u, &v);
		scanf("%d%d", &G[u][v], &cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra(st);
	DFS(ed);
	printf("%d %d\n", d[ed], c[ed]);
}
