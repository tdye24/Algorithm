#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int N, arr[maxn], suma, sumb;
int main() {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> arr[i];
	sort(arr, arr+N);
	for(int i=0; i<N/2; i++) {
		suma += arr[i];
	}
	if(N % 2 == 0) {
		for(int i=N/2; i<N; i++) 
			sumb += arr[i];
		cout << 0 << " " << abs(suma-sumb) << endl;
		return 0;
	} 
	if(N % 2 == 1) {
		for(int i=N/2+1; i<N; i++) 
			sumb += arr[i];
		int ans = max(abs(suma+arr[N/2]-sumb), abs(sumb+arr[N/2]-suma));
		cout << 1 << " " << ans << endl;
		return 0;
	}
	
} 
