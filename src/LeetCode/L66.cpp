#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
	int current, carry = 1;
	vector<int> ans;
    for(int i=digits.size()-1; i>=0; i--) {
		current = (digits[i]+carry)%10;
		carry = (digits[i]+carry)/10;
		ans.insert(ans.begin(), current);
	} 
	if(carry != 0)
		ans.insert(ans.begin(), carry);
	return ans;
}
int main() {
	vector<int> arr = {8,9,9,9};
	vector<int> ans = plusOne(arr);
	for(int i=0; i<ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}
