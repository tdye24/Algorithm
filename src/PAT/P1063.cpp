#include<bits/stdc++.h>
using namespace std;
set<int> arr[52];
int N, M, K;

void query(int a, int b) {
	int Nc = 0, Nt = 0;
	set<int>::iterator it1 = arr[a].begin();
	set<int>::iterator it2 = arr[b].begin(); 
	while(it1 != arr[a].end() && it2 != arr[b].end()) {
		if(*it1 < *it2) {
			it1++;
			Nt++;
		} else if(*it2 < *it1){
			it2++;
			Nt++;
		} else {
			it1++;
			it2++;
			Nc++;
			Nt++;
		}
	}
	while(it1 != arr[a].end()) {
		Nt++;
		it1++;
	}
	while(it2 != arr[b].end()) {
		Nt++;
		it2++;
	}
	printf("%.1f%%\n", Nc*1.0/Nt*100);
} 

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &M);
		int data;
		for(int j=0; j<M; j++) {
			scanf("%d", &data);
			arr[i].insert(data);
		}
	}
	scanf("%d", &K);
	int a, b;
	for(int i=0; i<K; i++) {
		scanf("%d%d", &a, &b);
		query(a, b);
	}
	return 0;
}
