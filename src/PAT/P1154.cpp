#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
pair<int, int> edges[maxn];
int color[maxn];
int main() {
	int N, M, K;
	cin >> N >> M;
	for(int i=0; i<M; i++) {
		cin >> edges[i].first >> edges[i].second;
	}
	cin >> K;
	for(int i=0; i<K; i++) {
		set<int> st;
		bool flag = false;
		for(int j=0; j<N; j++) {
			cin >> color[j];
			st.insert(color[j]);
		}
		for(int j=0; j<M; j++) {
			if(color[edges[j].first] == color[edges[j].second]) {
				flag = true;
				break;
			}	
		}
		if(flag) 
			cout << "No" << endl;
		else
			printf("%d-coloring\n", st.size());
	}
	return 0;
}
