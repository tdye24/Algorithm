#include<bits/stdc++.h>
using namespace std;
int arr[62];
int main() {
	string str;
	cin >> str;
	for(int i=0; i<str.length(); i++) {
		if(str[i] >='0' && str[i] <= '9') 
			arr[str[i] - 48] += 1;
		else if(str[i] >='A' && str[i] <= 'Z')
			arr[str[i] - 55] += 1;
		else if(str[i] >='a' && str[i] <= 'z')
			arr[str[i] - 61] += 1;
	}
	string s;
	cin >> s;
	bool flag = true;
	for(int i=0; i<s.length(); i++) {
		if(s[i] >='0' && s[i] <= '9') {
			arr[s[i] - 48] -= 1;
			if(arr[s[i] - 48] < 0)
				flag = false;
		} else if(s[i] >='A' && s[i] <= 'Z') {
			arr[s[i] - 55] -= 1;
			if(arr[s[i] - 55] < 0)
				flag = false;
		} else if(s[i] >='a' && s[i] <= 'z') {
			arr[s[i] - 61] -= 1;
			if(arr[s[i] - 61] < 0)
				flag = false;
		}
	}
	int ans = 0;
	if(flag == false) {
		printf("No ");
		for(int i=0; i<62; i++) {
			if(arr[i] < 0) {
				ans -= arr[i];
			}
		}
		printf("%d\n", ans);
	} else {
		printf("Yes ");
		for(int i=0; i<62; i++) {
			ans += arr[i];
		}
		printf("%d\n", ans);
	}
	return 0; 
}
