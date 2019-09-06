/*
*PAT 1152
*/
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    if(n == 1 || n == 0)  
        return false;
    int sqrn = (int)sqrt(n);
    for(int i=2; i<=sqrn; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n, k, data;
    string str, s;
    cin >> n >> k;
    cin >> str;
    for(int i=0; i<=n-k; i++) { //<=号！
        s = str.substr(i, k);
        data = stoi(s);
        if(isPrime(data)) {
            cout << s << endl;
            return 0;
        }    
    }
    cout << "404" << endl;
    return 0;
}