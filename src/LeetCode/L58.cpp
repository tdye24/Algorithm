#include<bits/stdc++.h>
using namespace std;
   
int lengthOfLastWord(string s) {
	if(s.length() == 0)
		return 0;
	for(auto it = s.end()-1; *it == 32; it--) 
		s.erase(it);
	if(s.length() == 0)
		return 0;
    int len = 0;
    for(auto it = s.end()-1; *it != 32; it--) {
        len++;
        if(it == s.begin())	
			break;
    }
    return len;
}

int main() {
	string s = " ";
	printf("%d", lengthOfLastWord(s));
	return 0;
}

