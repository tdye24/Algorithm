#include<bits/stdc++.h>
using namespace std;
const int maxn = 200010;
long int arr[maxn];
const int INF = 0x3f3f3f3f;
int main() {
	int N1;
	cin >> N1;
	for(int i=1; i<=N1; i++) 
		cin >> arr[i];
	arr[N1+1] = INF; //第二个数组的最大值可能超多第一个数组的最大值 
	int N2;
	long int data;
	cin >> N2;
	int mid = (N1+N2+1)/2, i = 1, count = 0;
	for(int j=1; j<=N2; j++) {
		cin >> data;
		while(arr[i] < data) {
			count++;
			if(count == mid) {
				cout << arr[i];
				return 0;
			}	
			i++;
		}
		count++;
		if(count == mid) {
			cout << data;
			return 0;
		}		
	}
	while(i<=N1) {
		count++;
		if(count == mid) {
			cout << arr[i];
			return 0;
		}
		i++;
	}
	return 0;
}
