#include<bits/stdc++.h>
using namespace std;
string in;
map<string, int> mp;
bool alphanumerical(char x) {
    if(isdigit(x)||isalpha(x)) return true;
    return false;
}
int main() {
    getline(cin, in);
    for(int i=0; i<in.size(); i++) {
        if(in[i]>='A' && in[i]<='Z') {
            in[i] += 32;
        }
    }
    string temp = "";
    int maxn = 0;
    for(int i=0; i<in.size(); i++) {
        if(alphanumerical(in[i])) {
            temp += in[i];
            if(i == in.size()-1) {
                 mp[temp]++;
                 if(mp[temp] > maxn) {
                    maxn = mp[temp];
                }
            }
               
        } else if(i == in.size()-1 || alphanumerical(in[i+1])) {
            mp[temp]++;
            if(mp[temp] > maxn) {
                maxn = mp[temp];
            }
            temp = "";
        }
    }
    for(auto it:mp) {
        if(it.second == maxn) {
            cout << it.first << " " << it.second << endl;
            break;
        }    
    }
    return 0;
}