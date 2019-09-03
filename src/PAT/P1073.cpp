#include<bits/stdc++.h>
using namespace std;

int main() {
	string in;
	cin >> in;
	char sign1 = in[0];
	char sign2;
	string exp = ""; 
	for(int i=in.length()-1; ; i--) {
		if(in[i] == '+' || in[i] == '-') {
			sign2 = in[i];
			break;
		}
		exp = in[i] + exp;	
	}
	int e = stoi(exp);
	string ans = "";
	for(int i=1; ; i++) {
		if(in[i] == 'E')
			break;
		ans += in[i];	
	}
	//求出小数点的位置
	int point_pos = ans.length() - 1;
	for(; point_pos>=0; point_pos--) {
		if(ans[point_pos] == '.')
			break;
	} 
	if(sign2 == '+') { //右移 
		while(point_pos < ans.length()-1 && e > 0) {
			swap(ans[point_pos], ans[point_pos+1]);
			point_pos++;
			e--;
		}
		while(e > 0) {
			ans = ans + '0';
			swap(ans[ans.length()-2], ans[ans.length()-1]);
			e--;
		}
	} else { //左移 
		while(point_pos > 0 && e > 0) {
			swap(ans[point_pos], ans[point_pos-1]);
			point_pos--;
			e--;
		}
		while(e > 0) {
			ans = '0' + ans ;
			swap(ans[0], ans[1]);
			e--;
		}
	} 
	if(sign1 == '-') 
		cout << sign1; 
	if(sign2 == '+') {
		for(int i=0; i<ans.length(); i++) {
			if(i==ans.length()-1 && ans[i] == '.')
				break;
			cout << ans[i];
		}
	} else {
		if(ans[0] == '.') 
			ans = '0' + ans;
		cout << ans << endl;
	}
	return 0;
} 
