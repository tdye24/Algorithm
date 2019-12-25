/*给定两个字符串形式的非负整数?num1 和num2?，计算它们的和。
注意：
num1 和num2?的长度都小于 5100.
num1 和num2 都只包含数字0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库，也不能直接将输入的字符串转换为整数形式。
*/

#include<bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2) {
	string ans = "";
	char current_str[2];
	int len1 = num1.size(), len2 = num2.size();
	int current, carry = 0, a, b, i, j;
	for(i=len1-1, j=len2-1; i>=0 && j>=0; i--, j--) {
		a = num1[i] - '0';
		b = num2[j] - '0';
		current = (a+b+carry) % 10;
		carry = (a+b+carry) / 10;
		itoa(current, current_str, 10);
		ans = current_str + ans;
	}
	
	if(i<0) {
		while(j>=0) {
			b = num2[j--] - '0'; 
			current = (b+carry) % 10;
			carry = (b+carry) / 10;
			itoa(current, current_str, 10);
			ans = current_str + ans;
		} 	
	} else {
		while(i>=0) {
			a = num1[i--] - '0'; 
			current = (a+carry) % 10;
			carry = (a+carry) / 10;
			itoa(current, current_str, 10);
			ans = current_str + ans;
		} 	
	}
	if(carry != 0) {
		itoa(carry, current_str, 10);
		ans = current_str + ans;
	}
    return ans;    
}

int main() {
	string num1 = "1", num2 = "9";
	cout << addStrings(num1, num2) << endl;
	return 0;
} 
