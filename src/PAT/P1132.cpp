#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool test(string str) {
	int Z = stoi(str.substr(0, str.size()));
	string 	s1 = str.substr(0, str.size()/2),
			s2 = str.substr(str.size()/2);
	int A = stoi(s1), B = stoi(s2);
	if(A*B != 0 && Z%(A*B) == 0) //A*B £¡= 0×¢ÒâÅÐ¶Ï¡£±ÈÈç4000 
		return true;
	return false;
}

int main() {
	int N;
	string str;
	cin >> N;
	while(N--) {
		cin >> str;
		if(test(str))
			printf("Yes\n");
		else 
			printf("No\n");	
	} 
	return 0;
} 
