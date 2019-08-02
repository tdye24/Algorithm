#include<bits/stdc++.h>
using namespace std;
int n, G[MAXV][MAXV]; //n为顶点数，MAXV为最大顶点数
bool inq[MAXV] = {false}; //若顶点i曾入过队列，则inq[i]==true。初值为false

void BFS(int u) { //遍历u所在的连通块 
	queue<int> q; //定义队列q
	q.push(u); //将初始点u入队
	inq[u] = true; //设置u已被加入过队列
	while(!q.empty()) {
		int u = q.front(); //取出队首元素
		printf("%d ", u); //访问u 
		q.pop(); //将队首元素出队
		for(int v=0; v<n; v++) {
			//如果u的邻接点v未曾如果队列 
			if(inq[v] == false && G[u][v] != INF) {
				q.push(v); //将v入队
				inq[v] = true; //标记v为已被加入过队列 
			} 
		} 
	} 
} 

void BFSTravel() { //遍历图G 
	for(int u=0; u<n; u++) { //枚举所有顶点 
		if(inq[u] == false) { //如果u未曾加入过队列 
			BFS(u); //遍历u所在的连通块 
		} 
	} 
} 

int main() {
	
}
