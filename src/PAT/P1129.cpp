#include<bits/stdc++.h>
#include <functional>
using namespace std;
const int maxk = 10;
int N, K;
int rec[maxk], num = 0;
map<int, int> mp; //id->count 
int main() {
	scanf("%d%d", &N, &K);
	int id, t;
	scanf("%d", &id);
	mp[id] = 1;
	rec[0] = id;
	num++;
	for(int i=1; i<N; i++) {
		scanf("%d", &id);
		printf("%d: ", id);
		for(int j=0; j<min(num, K); j++) {
			if(j == 0)
				printf("%d", rec[j]);
			else
				printf(" %d", rec[j]);
		}	
		printf("\n");
		if(mp.find(id) != mp.end()) 
			mp[id]++; 
		else
			mp[id] = 1;
		int s;
		bool flag = false;	
		for(s=0; s<num; s++) {
			if(rec[s] == id) {
				flag = true; //前几个数中包含了id 
				break;
			}	
		}
		if(flag) {
			for(int j=s; j>=1; j--) {
				if(mp[rec[j]] > mp[rec[j-1]] || (mp[rec[j]] == mp[rec[j-1]] && rec[j] < rec[j-1])) {
					t = rec[j-1];
					rec[j-1] = rec[j];
					rec[j] = t;	
				} 	 
			} 
		} else {
			if(mp[id] > mp[num-1] && num == 10) 
				rec[num-1] = id;
			else if(num < 10) {
				rec[num++] = id;
			}
			for(int j=num-1; j>=1; j--) {
				if(mp[rec[j]] > mp[rec[j-1]] || (mp[rec[j]] == mp[rec[j-1]] && rec[j] < rec[j-1])) {
					t = rec[j-1];
					rec[j-1] = rec[j];
					rec[j] = t;	
				} 		 
			} 
		}	
	}
} 
