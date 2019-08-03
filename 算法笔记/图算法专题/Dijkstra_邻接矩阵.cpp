#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1000; //最大顶点数
const int INF = 1000000000; //设INF为一个很大的数 

int n, G[MAXV][MAXV]; //n为顶点数，MAXV为最大顶点数
int d[MAXV]; //起点到达各点的最短路径长度
bool vis[MAXV] = {false}; //标记数组，vis[i] = true表示已访问。初值均为false

void Dijkstra(int s) { //s为起点 
	fill(d, d+MAXV, INF); //fill函数将整个d数组赋值为INF（慎用memset）
	d[s] = 0;
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
			if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v]; //优化d[v] 
			} 
		} 
	} 
} 
