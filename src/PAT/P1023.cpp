#include<bits/stdc++.h>
#include<string>
using namespace std;
int arr[10];
string doub(string str) {
	string ans = "";
	int current, carry = 0;
	for(int i=str.length()-1; i>=0; i--) {
		int t1 = str[i] - '0';
		current = (t1+t1+carry)%10;
		carry = (t1+t1+carry)/10;
		ans = to_string(current) + ans;
	}
	if(carry >= 1) {
		ans = "1" + ans;
	}
	return ans;
}

int main() {
	string str;
	cin >> str;
	for(int i=0; i<str.length(); i++) {
		arr[str[i]-'0']++;
	}
	str = doub(str);
	for(int i=0; i<str.length(); i++) {
		arr[str[i]-'0']--;
	}
	bool flag = true;
	for(int i=0; i<10; i++) {
		if(arr[i] != 0) {
			flag = false;
			break;
		}
	}
	if(flag)	
		cout << "Yes" << endl << str << endl;
	else 
		cout << "No" << endl << str << endl;
	return 0;
} 
