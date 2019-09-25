/*
*PAT 1083
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct Node {
	string name, id;
	int grade;
} nodes[maxn];

bool cmp(Node a, Node b) {
	return a.grade > b.grade;
}

int main() {
	int n, count = 0, low, up;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> nodes[i].name >> nodes[i].id >> nodes[i].grade;
	}
	sort(nodes, nodes+n, cmp);
	cin >> low >> up;
	for(int i=0; i<n; i++) {
		if(nodes[i].grade >= low && nodes[i].grade <= up) {
			count++;
			cout << nodes[i].name << " " << nodes[i].id << endl;
		}
	}
	if(count == 0) {
		cout << "NONE";
	}
	return 0;
}
