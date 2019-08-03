#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1010;
struct Node {
	int id; //节点编号 
	int layer; //节点层号 
};

vector<Node> Adj[MAXV]; //邻接表 
bool inq[MAXV] = {false}; //顶点是否已被加入过队列

int BFS(int s, int L) { //start为起始节点，L为层数上限 
	int numForward = 0; //转发数
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inq[start.id] = true;
	while(!q.empty()) {
		Node topNode = q.front();
		q.pop();
		int u = topNode.id;
		for(int i=0; i<Adj[u].size(); i++) {
			Node next = Adj[u][i];
			next.layer = topNode.layer + 1;
			if(inq[next.id] == false && next.layer <= L) {
				q.push(next);
				inq[next.id] = true;
				numForward ++;
			}
		}
	} 
	return numForward;
} 

int main() { 
	Node user;
	int n, L, numFollow, idFollow;
	scanf("%d%d", &n, &L); //节点数、层数上限
	for(int i=1; i<=n; i++) {
		user.id = i;
		scanf("%d", &numFollow); //i号用户关注的人数
		for(int j=0; j<numFollow; j++) {
			scanf("%d", &idFollow);
			Adj[idFollow].push_back(user); //边idFollow->i 
		}
		
	}
	int numQuery, s;
	scanf("%d", &numQuery);
	for(int i=0; i<numQuery; i++) {
		memset(inq, false, sizeof(inq)); //inq数组初始化
		scanf("%d", &s);
		int numForward = BFS(s, L);
		printf("%d\n", numForward); 
	}
	return 0;
} 
