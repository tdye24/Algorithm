#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct Node {
	bool flag;
	int data, left, right, level;
} nodes[maxn];
int N, data, suma, sumb, maxl;
int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> data;
		int root = 0, level = 0;
		while(nodes[root].flag) {
			if(data <= nodes[root].data) {
				if(nodes[root].left == 0) 
					nodes[root].left = i;
				root = nodes[root].left;
			} else {
				if(nodes[root].right == 0) 
					nodes[root].right = i;
				root = nodes[root].right;
			}	
			level++;
		}
		nodes[root].flag = true;
		nodes[root].data = data;
		nodes[root].level = level;
		maxl = max(maxl, level);
	}
	for(int i=0; i<N; i++) {
		if(nodes[i].level == maxl) {
			suma++;
			continue;
		}	
		if(nodes[i].level == maxl-1) {
			sumb++;
			continue;
		}
			
	}
	cout << suma << " + " << sumb << " = " << suma+sumb << endl;
	return 0;
}
