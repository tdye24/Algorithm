/*
*PAT 1084 ×Ö·û´® 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int arr[maxn] = {0};

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	
	for(int i=0, j=0; i<s1.length(); ) {
		if(abs(s2[j]-s1[i]) == 32 || abs(s2[j]-s1[i]) == 0) {
			j++;
			i++; 
		} else {
			char ch = s1[i];
			if(ch >= 'a' && ch <= 'z') {
				ch = ch - 32;
			}
			if(arr[ch] == 0) {
				cout << ch;
				arr[ch]++;
			}	
			i++;
		}	
	}
	return 0;
} 
