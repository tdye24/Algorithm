#include<bits/stdc++.h>
using namespace std;

struct Node {
	int v; //顶点编号
	int layer; //顶点层号 
}; 

vector<Node> Adj[MAXV]; //图G， Adj[u]存放从顶点u出发可以到达的所有顶点
int n; //n为顶点数，MAXV为最大顶点数
bool inq[MAXV] = {false}; //若顶点i曾入过队列，则inq[i]==true。初值为false

void BFS(int s) { //s为起始顶点编号 
	queue<Node> q; //BFS队列q
	Node start; //起始顶点
	start.v = s; //起始顶点编号
	start.layer = 0; //起始顶点层号为0
	q.push(start); //将起始顶点压入队列 
	inq[start.v] = true; //设置u已被加入过队列
	while(!q.empty()) { //只要队列非空 
		Node topNode = q.front(); //取出队首元素
		printf("%d-%d ", topNode.v, topNode.layer); //访问u 
		q.pop(); //将队首元素出队 
		for(int i=0; i<Adj[u].size(); i++) { //枚举u出发能到达的所有顶点 
			Node next = Adj[u][i];
			next.layer = topNode.layer + 1;
			if(inq[next.v] == false) { //如果v未曾加入过队列 
				q.push(next); //将v入队
				inq[next.v] = true; //标记v以被加入过队列 
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

