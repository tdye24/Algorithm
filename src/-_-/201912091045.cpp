/**
*×Ö·û´®s = "ajkdjkajfdkjfddd" 
**/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn = 26;
bool already[maxn];
int main() {
	string s = "ajkdjkajfdkjfddd";
	for(int i=0; i<s.size(); i++) {
		if(!already[s[i]-'a'])	already[s[i]-'a'] = true;
	}
	for(int i=0; i<26; i++) {
		if(already[i])	printf("%c", 'a'+i);
	}
	return 0;
}
