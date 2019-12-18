#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size(), m = obstacleGrid[0].size(), xlimit = 0, ylimit = 0;
    ll d[n][m];
	fill(d[0], d[0]+n*m, 0);
    while(xlimit < n && obstacleGrid[xlimit][0] == 0) 
        xlimit++;
    while(ylimit < m && obstacleGrid[0][ylimit] == 0)
        ylimit++;
    for(int i=0; i<xlimit; i++) 
        d[i][0] = 1;
    for(int i=0; i<ylimit; i++)
        d[0][i] = 1;
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(obstacleGrid[i][j] == 1) 
                d[i][j] = 0;
            else 
                d[i][j] = d[i][j-1] + d[i-1][j];
        }
    }
    return d[n-1][m-1];
    
}

int main() {
	vector<vector<int>> vec = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}; 
	printf("%d", uniquePathsWithObstacles(vec));
	return 0;
}
