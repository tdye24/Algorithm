#include<bits/stdc++.h>
using namespace std;
string s1, s2;
const int maxn = 128;
int book[maxn];
int main() {
	getline(cin, s1);
	getline(cin, s2);
	for(int i=0; i<s2.length(); i++)
		if(book[s2[i]] == 0) 
			book[s2[i]]++;
	for(int i=0; i<s1.length(); i++) 
		if(book[s1[i]] == 0) 
			cout << s1[i];
 	return 0;
} 
