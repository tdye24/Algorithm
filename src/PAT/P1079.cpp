/*
* PAT 1079
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> nodes[maxn];
int leaves[maxn] = {0};
int n, k, data, depth;
double price, r, ans;

void DFS(int start, int depth) {
	if(nodes[start].size() != 0) {
		for(int i=0; i<nodes[start].size(); i++) {
			DFS(nodes[start][i], depth+1);
		}
	} else {
		ans += price*pow(1.0+r, depth)*leaves[start];
		return;
	}
	
}

int main() {
	cin >> n >> price >> r;
	r /= 100.0;
	for(int i=0; i<n; i++) {
		cin >> k;
		if(k != 0) {
			for(int j=0; j<k; j++) {
				cin >> data;
				nodes[i].push_back(data);
			}	
		} else {
			cin >> data;
			leaves[i] = data;
		}	
	}
	DFS(0, 0);
	printf("%.1f", ans);
	return 0;
}
