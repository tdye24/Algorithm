#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1000; //最大顶点数
const int INF = 1000000000; //设INF为一个很大的数 

int n, G[MAXV][MAXV]; //n为顶点数，MAXV为最大顶点数
int d[MAXV]; //起点到达各点的最短路径长度
int pre[MAXV]; //pre[v]表示表示起点到达顶点v的最短路径上v的前一个顶点（新添加） 
bool vis[MAXV] = {false}; //标记数组，vis[i] = true表示已访问。初值均为false

void Dijkstra(int s) { //s为起点 
	fill(d, d+MAXV, INF); //fill函数将整个d数组赋值为INF（慎用memset）
	for(int i=0; i<n; i++) {
		pre[i] = i; //初始状态设每个点的前驱为自身（新添加） 
	}
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
				pre[v] = u; //记录v的前驱节点是u（新添加） 
			} 
		} 
	} 
} 


void DFS(int s, int v) { //s为起点编号，v为当前访问的顶点编号（从终点开始递归） 
	if(v == s) { //如果当前已经到达起点s，则输出起点并返回
		printf("%d\n", s);
		return; 
	} 
	DFS(s, pre[v]); //递归访问v的前驱顶点pre[v]
	printf("%d\n", v); 
} 
