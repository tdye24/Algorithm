/*
*1098 Insert or Merge (25 分)
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, a[100], b[100], i, j;
	cin >> n;
	for(int i=0; i<n; i++) 
		cin >> a[i];
	for(int i=0; i<n; i++)
		cin >> b[i];
	for(i=0; i<n-1 && b[i] <= b[i+1]; i++); //分号很重要 
	
	for(j = i+1; a[j] == b[j] && j < n; j++); //分号很重要 
	if(j == n) {
		cout << "Insertion Sort" << endl;
		sort(a, a+i+2); //i+2 个元素 
	} else {
		cout << "Merge Sort" << endl;
		int k = 1, flag = 1;
		while(flag) {
			flag = 0;
			//检查是是否排序到该种程度 
			for(i=0; i<n; i++) {
				if(a[i] != b[i])
					flag = 1;
			} 
			k = k*2;
			for(i=0; i<n/k; i++) 
				sort(a+i*k, a+(i+1)*k);
			sort(a+n/k*k, a+n); //尾部剩余的几个元素 
		}
	} 
	for(j=0; j<n; j++) {
		if(j != 0) 	printf(" ");
		printf("%d", a[j]);
	}
	return 0; 
}
