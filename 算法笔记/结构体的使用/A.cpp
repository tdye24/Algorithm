#include<bits/stdc++.h>
using namespace std;
struct preson{
	char name[20];
	int count;
} leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0};
int main() {
	int n;
	scanf("%d", &n);
	string s;
	while(n--) {
		cin >> s; 
		for(int i=0; i<3; i++) {
			if(leader[i].name == s)
				leader[i].count ++;
		}
	}
	for(int i=0; i<3; i++)
		printf("%s:%d\n", leader[i].name, leader[i].count);
	return 0;
}
