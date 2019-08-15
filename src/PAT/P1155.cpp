#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int arr[maxn];
vector<int> path; 
int N;
bool max_heap = false, min_heap = false, not_heap = false;
void DFS(int v) {
	if(v*2 > N) {
		path.push_back(arr[v]);
		for(int i=0; i<path.size(); i++) {
			if(i==0) 
				printf("%d", path[i]);
			else
				printf(" %d", path[i]);		
		}
		printf("\n");
		int k = 1;
		if(max_heap) {
			while(k<path.size() && path[k] < path[k-1])
				k++;
		}
		if(min_heap) {
			while(k<path.size() && path[k] > path[k-1])
				k++;
		}
		if(k != path.size()) 
			not_heap = true;
		path.pop_back();
		return;
	}
	path.push_back(arr[v]);
	if(v*2+1<=N)
		DFS(v*2+1);
	if(v*2<=N)
		DFS(v*2);
	path.pop_back();
} 

int main() {
	scanf("%d", &N);
	vector<int> path;
	for(int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
	}
	if(arr[1]>arr[2])
		max_heap = true;
	else
		min_heap = true;
	DFS(1);
	if(not_heap)
		printf("Not Heap\n");
	else if(max_heap)
		printf("Max Heap\n");
	else
		printf("Min Heap\n");
	return 0;
} 

