#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	scanf("%d\n", &n);
	char suffix[300], str[300];
	cin.getline(suffix, 300);
	for(int k=0; k<n-1; k++) {
		cin.getline(str, 300);
		for(int i=strlen(suffix)-1, j=strlen(str)-1; i>=0&&j>=0; i--, j--) {
			int len = strlen(suffix);
			if(suffix[i] != str[j]) {
				int t = 0;
				i++;
				while(i<len) {
					suffix[t++] = suffix[i++];
				}
				suffix[t] = '\0';
				break;
			}
		}
	}
	if(strlen(suffix) == 0)
		printf("nai\n");
	else 
		printf("%s\n", suffix);
	return 0;
} 
