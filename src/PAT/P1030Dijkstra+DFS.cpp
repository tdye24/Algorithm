#include<bits/stdc++.h>
using namespace std;
const int MAXV = 510;
const int INF = 1000000000;
int n; //节点总数 
int m; //边数 
int start, end;
int G[MAXV][MAXV];
int d[MAXV];
vector<int> pre[MAXV]; //存放节点的前驱节点 
int vis[MAXV] = {false};
int optValue = INF; //第二标尺最优值 
vector<int> path, tempPath; //最优路径，临时路径 

int V[MAXV][MAXV]; //边权 

void Dijkstra(int s) { //s为起点
	fill(d, d+MAXV, INF);
	d[s] = 0;
	for(int i=0; i<n; i++) { //循环n次 
		int u = -1, MIN = INF;
		for(int j=0; j<n; j++) {
			if(vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		} 
		if(u == -1)
			return;
		vis[u] = true;
		for(int v=0; v<n; v++) {
			if(vis[v] == false && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v]; //优化d[v]
					pre[v].clear(); //清空pre[v]
					pre[v].push_back(u); //令v的前驱为u 
				} else if(d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u); //令v的前驱为u 
				}
			}
		}
	} 	
}

void DFS(int v) { //v为当前访问节点 
	//递归边界 
	if(v == start) { //如果到达了叶子节点start（即路径的起点）
		tempPath.push_back(v);  //即将起点start加入临时路径tempPath的最后面
		int value = 0; //存放临时路径tempPath的第二标尺的值
		//计算tempPath上的value值
		
		//边权之和 
		for(int i=tempPath.size()-1; i>0; i--) { //逆序访问节点，循环条件为i>0
			//当前节点id，下一节点idNext
			int id = tempPath[i], idNext = tempPath[i-1];
			value += V[id][idNext]; //value增加边id->idNext的边权 	
		} 
		
		if(value < optValue) { //如果当前值优于最优值 
			optValue = value; //更新第二标尺最优值与最优路径
			path = tempPath; 
		}
		tempPath.pop_back(); //将刚加入的节点删除
		return;
	}
	
	//递归式
	tempPath.push_back(v); //将当前访问节点加入临时路径tempPath的最后面
	for(int i=0; i<pre[v].size(); i++) {
		DFS(pre[v][i]); //节点v的前驱节点pre[v][i]，递归 
	} 
	tempPath.pop_back(); //遍历完所有前驱节点，将当前节点v删除 
} 

int main() {
	scanf("%d%d%d%d", &n, &m, &start, &end);
	int from, to, dis, cost;
	fill(G[0], G[0]+MAXV*MAXV, INF); //初始化图G
	fill(V[0], V[0]+MAXV*MAXV, INF); 
	for(int i=0; i<m; i++) {
		scanf("%d%d%d%d", &from, &to, &dis, &cost);
		G[from][to] = G[to][from] = dis;
		V[from][to] = V[to][from] = cost;
	}
	
	
	Dijkstra(start);
	DFS(end);
	for(int i=path.size()-1; i>=0; i--) {
		printf("%d ", path[i]);
	} 
	printf("%d %d\n", d[end], optValue);
	return 0;	
}
