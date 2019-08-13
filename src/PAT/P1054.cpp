#include<bits/stdc++.h>
using namespace std;
int M, N;
unordered_map<string, int> mp;
int main() {
	string str;
	scanf("%d%d", &M, &N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin >> str;
			if(mp.find(str) == mp.end())
				mp[str] = 1;
			else 
				mp[str]++;
		}
	}
	string color;
	int dominant = 0;
	for(unordered_map<string, int>::iterator it=mp.begin(); it!=mp.end(); it++) {
		if(it->second > dominant) {
			color = it->first;
			dominant = it->second;
		}
			
	}
	cout << color << endl;
	return 0;
}
