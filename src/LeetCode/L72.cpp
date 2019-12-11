#include<bits/stdc++.h>
using namespace std;
const int maxn = 1024;
int dist[maxn][maxn];
int minDistance(string word1, string word2) {
	int len1 = word1.length(), len2 = word2.length();
	for(int i=0; i<=len2; i++)	
		dist[0][i] = i;
	for(int j=0; j<=len1; j++)
		dist[j][0] = j;
	
	for(int i=1; i<=len1; i++) {
		for(int j=1; j<=len2; j++) {
			if(word1[i-1] == word2[j-1])	
				dist[i][j] = dist[i-1][j-1];
			else
				dist[i][j] = min(min(dist[i-1][j-1], dist[i-1][j]), dist[i][j-1]) + 1;
		}
	}
	return dist[len1][len2];
}

int main() {
	string s1 = "intention", s2 = "execution";
	int mindis = minDistance(s1, s2);
	printf("%d", mindis);
	return 0;
}
