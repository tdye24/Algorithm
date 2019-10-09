/*
* PAT1074 Reversing Linked List
*/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct Node {
	int address, data, next;
} nodes[maxn];
vector<int> add;
int start, N, K;

int main() {
	int address, data, next, cnt = 0;
	stack<Node> st;
	cin >> start >> N >> K;
	for(int i=0; i<N; i++) {
		cin >> address >> data >> next;
		nodes[address] = {address, data, next};
	}
	int tt = start;
	while(tt != -1) {
		add.push_back(nodes[tt].address);
		tt = nodes[tt].next;
	}
	int c = 0;
	while(c + K <= N) {
		reverse(add.begin() + c, add.begin() + c + K);
		c += K;
	}
	for(int i=0; i<add.size(); i++) {
		address = add[i];
		next = add[i+1];
		if(i != add.size()-1)
			printf("%05d %d %05d\n", address, nodes[address].data, next);
		else 
			printf("%05d %d -1\n", address, nodes[address].data);
	}
	return 0;
}
