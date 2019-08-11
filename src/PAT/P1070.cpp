#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct Node {
	float amount;
	float price;
} nodes[maxn];

int N;
float D;

bool cmp(Node a, Node b) {
	if(a.price/a.amount == b.price/b.amount)
		return a.amount > b.amount;
	else 
		return a.price/a.amount > b.price/b.amount;
}

int main() {
	scanf("%d", &N);
	scanf("%f", &D);
	for(int i=0; i<N; i++)
		scanf("%f", &nodes[i].amount);
	for(int i=0; i<N; i++) 
		scanf("%f", &nodes[i].price);
	sort(nodes, nodes+N, cmp);
	float ans = 0.0;
	int i = 0;
	while(i<N) {
		if(nodes[i].amount <= D) {
			D -= nodes[i].amount;
			ans += nodes[i++].price;
		} else {
			ans += nodes[i].price/nodes[i].amount*D;
			break; 
		}
	}
	printf("%.2f\n", ans);
	return 0;
		
}
