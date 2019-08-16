#include<bits/stdc++.h>
using namespace std;
const int maxn = 60;
int K;
string arr[maxn];
int shuf[maxn];

string int2str(int n) {
	string str = "";
	switch(n/13) {
		case 0: {
			str = "S" + to_string(n%13+1);
			break;
		}
		case 1: {
			str = "H" + to_string(n%13+1);
			break;
		}
		case 2: {
			str = "C" + to_string(n%13+1);
			break;
		}
		case 3: {
			str = "D" + to_string(n%13+1);
			break;
		}
		case 4: {
			str = "J" + to_string(n%13+1);
			break;
		}
	}
	return str;
}

int main() {
	scanf("%d", &K);
	for(int i=0; i<54; i++) 
		scanf("%d", &shuf[i]);
	string card = "";
	int pos = -1;
	for(int i=0; i<54; i++) {
		card = int2str(i);
		pos = i+1;
		for(int j=0; j<K; j++) {
			pos = shuf[pos-1];
		}
		arr[pos] = card;
	}
	for(int i=1; i<=54; i++) {
		if(i == 1)
			cout << arr[i];
		else
			cout << " " << arr[i];
	}
	cout << endl;
	return 0;
} 
