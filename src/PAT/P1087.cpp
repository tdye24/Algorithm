#include<bits/stdc++.h>
using namespace std;
const int MAXV = 210;
const int INF = 1000000000;
int n, k; //节点总数 、边的数量 
int G[MAXV][MAXV];
int vis[MAXV] = {false};
int d[MAXV];

vector<int> pre[MAXV]; //存放节点的前驱节点 
vector<int> path, tempPath; //最优路径，临时路径 
int W[MAXV]; //点权 =>happiness
int optValue; //第二标尺最优值 

int num[MAXV]; //令起点s到达顶点u的最短路径条数为num[u]，初始化时只有num[s]为1，其余num[u]均为0 

int st, ed;

map<string, int> mp;

void Dijkstra(int s) { //s为起点
	d[s] = 0;
	memset(num, 0, sizeof(num));
	num[s] = 1;
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
					num[v] = num[u];
					pre[v].clear(); //清空pre[v]
					pre[v].push_back(u); //令v的前驱为u 
				} else if(d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u); //令v的前驱为u 
					num[v] += num[u];
				}
			}
		}
	} 	
}

void DFS(int v) { //v为当前访问节点 
	//递归边界 
	if(v == st) { //如果到达了叶子节点start（即路径的起点）
		tempPath.push_back(v);  //即将起点start加入临时路径tempPath的最后面
		int value = 0; //存放临时路径tempPath的第二标尺的值
		//计算tempPath上的value值
		
		//点权之和
		for(int i=tempPath.size()-1; i>=0; i--) { //逆序访问节点，循环条件为i>=0
			//当前节点id，下一节点idNext
			int id = tempPath[i];
			value += W[id]; //value增加边id的点权 	
		}  
		
		if(value > optValue) { //如果当前值优于最优值 
			optValue = value; //更新第二标尺最优值与最优路径
			path = tempPath; 
		} else if(value == optValue) {
			if(tempPath.size() < path.size())
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

string int2str(int n) {
	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if(it->second == n) 
			return it->first;
	}
}

int main() {
	string address;
	int happiness;
	scanf("%d %d", &n, &k);
	getchar();
	cin >> address;
	mp[address] = 0;
	W[0] = 0;
	st = 0;
	for(int i=1; i<n; i++) {
		cin >> address >> happiness;
		mp[address] = i;
		if(address == "ROM")
			ed = i;
		W[i] = happiness;
	}
	string from_str, to_str;
	int from, to, cost;
	fill(d, d+MAXV, INF);
	fill(G[0], G[0]+MAXV*MAXV, INF);
	for(int i=0; i<k; i++) {
		cin >> from_str >> to_str >> cost;
		from = mp[from_str];
		to = mp[to_str];
		G[from][to] = cost;
		G[to][from] = cost;
	}
	
	Dijkstra(st);
	DFS(ed);
	printf("%d %d %d %d\n", num[ed], d[ed], optValue, optValue/(path.size()-1));
	for(int i=path.size()-1; i>=0; i--) {
		if(i == path.size()-1)
			cout << int2str(path[i]);
		else
			cout << "->" << int2str(path[i]);
	}
	printf("\n");
	return 0;	
}
