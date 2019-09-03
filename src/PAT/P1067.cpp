#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
map<int, int> mp;
int N, book, num;

void SWAP(int k) { //swap(0, *) 
	int t = mp[0];
	mp[0] = mp[k];
	mp[k] = t;
}

int main() {
	cin >> N;
	int left = N - 1; //除去零外未归位的数字个数 
	for(int i=0; i<N; i++) {
		cin >> book;
		mp[book] = i;
		if(book == i && book != 0) 
			left--;
		
	}
	int i = 1; //不应该从头搜索 
	while(left > 0) {
		if(mp[0] != 0) {
			SWAP(mp[0]);
			num++;
			left--; 
		} else {
			for(; i<N; i++) { //不应该从头搜索 
				if(mp[i] != i) {
					SWAP(i);
					num++;
					break;
				}
			}
		}
	}
	cout << num << endl;
	return 0;
}
