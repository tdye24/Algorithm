#include<bits/stdc++.h>
using namespace std;
const int maxn = 30010;
int table[maxn];

void Add(int i, int j) {
	table[i] += j;
}

void Sub(int i, int j) {
	table[i] -= j;
}

void Query(int i, int j) {
	int sum = 0;
	for(int k=i; k<=j; k++) {
		sum += table[k]; 
	}
	printf("%d\n", sum);
}

int main() {
	int T, N, data, p, q;
	scanf("%d", &T);
	for(int m=1; m<=T; m++) {
		string command = "";
		printf("Case %d:\n", m);
		scanf("%d", &N);
		for(int i=1; i<=N; i++) {
			scanf("%d", &data);
			table[i] = data;
		} 
		
		while(command != "End") {
			cin >> command;
			if(command == "Query") {
				scanf("%d%d", &p, &q);
				Query(p, q);
			} else if(command == "Add") {
				scanf("%d%d", &p, &q);
				Add(p, q);
			} else if(command == "Sub") {
				scanf("%d%d", &p, &q);
				Sub(p, q);
			}
		}	
	}
	return 0;
}
