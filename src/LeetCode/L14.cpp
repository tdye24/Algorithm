#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())
        return "";
    //找所有序列中长度最短的字符串，取其长度作为循环比价上限 
    int min_len = strs[0].size();
    for(int i=0; i<strs.size(); i++) 
    	min_len = strs[i].size() < min_len ? strs[i].size() : min_len;
	
    
    string ans;
    for(int j=0; j<min_len; j++) {
        vector<string>::iterator it = strs.begin();
        char c = (*it)[j];
        while(it != strs.end()) {
            if(c==(*it)[j]) 
                it++;
            else
                return ans;
        }
        ans += c;
    }
    return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<string> strs(n);
	for(int i=0; i<n; i++) {
		cin >> strs[i];
	}
	string ans = longestCommonPrefix(strs);
	cout << ans;
} 
