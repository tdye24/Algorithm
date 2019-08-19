#include<bits/stdc++.h>
using namespace std;
unsigned int BKDRHash(char * str) {
	unsigned int seed = 31, key = 0;
	while(*str) 
		key = key*seed + (*str++); 	
	return key & 0x7fffffff;
}
int N, K;
map<int, vector<int>> mp;
int main() {
	scanf("%d%d", &N, &K);
	int course = 0, num = 0;
	char name[5];
	for(int i=0; i<K; i++) {
		scanf("%d%d", &course, &num); 
		for(int j=0; j<num; j++) {
			scanf("%s", &name);
			mp[BKDRHash(name)].push_back(course);
		}
	}
	for(int i=0; i<N; i++) {
		scanf("%s", &name);
		sort(mp[BKDRHash(name)].begin(), mp[BKDRHash(name)].end());
		printf("%s %d", name, mp[BKDRHash(name)].size());
		for(int i=0; i<mp[BKDRHash(name)].size(); i++) 
			printf(" %d", mp[BKDRHash(name)][i]);
		printf("\n");
	}
	return 0;
} 
