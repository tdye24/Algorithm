/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。
机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？
*/
#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
	int d[n][m];
	fill(d[0], d[0]+n*m, 0);
	for(int i=0; i<n; i++) 
		d[i][0] = 1;
	for(int i=0; i<m; i++)
		d[0][i] = 1;
	for(int i=1; i<n; i++) {
		for(int j=1; j<m; j++) 
			d[i][j] = d[i][j-1] + d[i-1][j];
	}
	return d[n-1][m-1];
}

int main() {
	printf("%d", uniquePaths(7, 3));
	return 0;
}
