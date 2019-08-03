#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1000;
const int INF = 1000000000;
struct Node {
	int v; //v为边的目标顶点
	int dis; //dis为边权 
}; 
vector<Node> Adj[MAXV]; //图G，Adj[u]存放从顶点u出发可以到达的所有顶点
int n; //n为顶点数，图G使用邻接表实现，MAXV为最大顶点数
int d[MAXV]; //起点到达各点的最短路径 
bool vis[MAXV] = {false}; //标记数组，vis[i] == true表示已访问。初值均为false

void Dijkstra(int s) { //s为起点 
	fill(d, d+MAXV, INF); //fill函数将整个d数组赋值为INF（慎用memset）
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
		vis[u] = true;
		//只有下面这个for循环与邻接矩阵的写法不同
		for(int j=0; j<Adj[u].size(); j++) {
			int v = Adj[u][j].v; //通过邻接表直接获得u能到达的顶点v
			if(vis[v] == false && d[u] + Adj[u][j].dis < d[v]) {
				//如果v未访问&&以u为中介点可以使d[v]更优
				d[v] = d[u] + Adj[u][j].dis; //优化d[v] 
			} 
		} 
	}
} 

