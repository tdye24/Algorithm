#include<bits/stdc++.h>
using namespace std;
const int maxn = 24; //number of windows 
const int maxm = 12; //maxium capacity of each line inside the yellow line.
const int maxk = 1010; //number of customers
const int maxq = 1010; //number of customer queries 

queue<int> windows[maxn];
int times[maxk]; //serve time
int temp_times[maxk];
int ans[maxk]; //leave time 
int N, M, K, Q;
int liners = 0; 
int globaltime = 0;

pair<int, int> int2str(int n) {
	int minute = n%60;
	int hour = 8 + n/60;
	return pair<int, int>(hour, minute);
}

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for(int i=1; i<=K; i++) {
		scanf("%d", &times[i]);
		temp_times[i] = times[i];
	}
		
	
	
	
	for(int i=1; i<=K; i++) {
		if(liners >= N*M) {
			int v = 0, soonest =  10010, front = 0, tt = 0;
			for(int j=1; j<=N; j++) {
				front = windows[j].front();
				if(times[front] < soonest) {
					soonest = times[front];
					v = j;
				}
			}
			tt = times[windows[v].front()];
			for(int j=1; j<=N; j++) {
				front = windows[j].front();
				times[front] -= tt;
			}
			globaltime += tt;
			ans[windows[v].front()] = globaltime;
			windows[v].pop();	
			windows[v].push(i);
		} else {
			int v = 0, shortest = M+1;
			for(int j=1 ; j<=N; j++) {
				if(windows[j].size() < shortest) {
					shortest = windows[j].size();
					v = j;
				}
			}
			windows[v].push(i);
			liners++;
		}
	}
	
	
	while(liners != 0) {
		int soonest = 10010, v = 0, front = 0;
		for(int i=1; i<=N; i++) {
			if(!windows[i].empty()) {
				front = windows[i].front();
				if(times[front] < soonest) {
					soonest = times[front];
					v = i;
				}
			}
		}
		int tt = times[windows[v].front()];
		for(int j=1; j<=N; j++) {
			if(!windows[j].empty()) {
				front = windows[j].front();
				times[front] -= tt;
			}	
		}
		globaltime += tt;
		ans[windows[v].front()] = globaltime;
		windows[v].pop();
		liners--;		
	}
	
	int query = 0, hour, minute;
	for(int i=1; i<=Q; i++) {
		scanf("%d", &query);
		if(ans[query]-temp_times[query] >= 540) {
			printf("Sorry\n");
		} else {
			hour = int2str(ans[query]).first;
			minute = int2str(ans[query]).second;
			printf("%02d:%02d\n", hour, minute);
		} 
	}
	return 0;
}
