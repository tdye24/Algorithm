#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll CP[100005];
	ll CN[100005];
	int NC;
	cin >> NC;
	long C = 0;
	int m = 0, n = 0;
	for(int i=0; i<NC; i++) {
		cin >> C;
		if(C > 0) 
			CP[m++] = C;
		else 
			CN[n++] = C;
	}
	ll PP[100005];
	ll PN[100005];
	int NP;
	cin >> NP;
	ll P = 0;
	int p = 0, q = 0;
	for(int i=0; i<NP; i++) {
		cin >> P;
		if(P > 0)
			PP[p++] = P;
		else
			PN[q++] = P;
	}
	
	sort(CP, CP+m);
	sort(PP, PP+p);
	
	sort(CN, CN+n);
	sort(PN, PN+q);
	
	long long sum = 0;
	for(int i=m-1, j=p-1; i>=0 && j>=0; i--, j--)
		sum += CP[i]*PP[j];
	for(int i=0, j=0; i<n && j<q; i++, j++)
		sum += CN[i]*PN[j];
	cout << sum << endl;	
}
