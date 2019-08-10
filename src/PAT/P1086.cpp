#include<bits/stdc++.h>
using namespace std;
const int maxn = 32;
struct Node {
	int push;
	int pop;
	int l;
	int r;
	vector<int> left;
	vector<int> right;
	bool flag;
} nodes[maxn];
int n;
stack<int> st;
int num;

int Build(vector<int> vec) {
	if(vec.size() == 1) 
		return *vec.begin();
	else {
		int root = vec[0];
		for(int i=1; i<vec.size(); i++) {
			if(nodes[vec[i]].push>nodes[root].push && nodes[vec[i]].pop<nodes[root].pop)
				nodes[root].left.push_back(vec[i]);
			else 
				nodes[root].right.push_back(vec[i]);
		}
		if(nodes[root].left.size()>0)
			nodes[root].l = Build(nodes[root].left);
		if(nodes[root].right.size()>0)
			nodes[root].r = Build(nodes[root].right);
		return root;
	}
	
}

void PostOrder(int root) {
	if(root == 0)
		return;
	PostOrder(nodes[root].l);
	PostOrder(nodes[root].r);
	num++;
	if(num == 1)
		printf("%d", root);
	else 
		printf(" %d", root);
}

int main() {
	scanf("%d", &n);
	string op;
	int id;
	vector<int> vec;
	for(int i=1; i<=2*n; i++) {
		cin >> op;
		if(op == "Push") {
			scanf("%d", &id);
			st.push(id);
			vec.push_back(id);
			nodes[id].push = i;
		} else if(op == "Pop") {
			id = st.top();
			st.pop();
			nodes[id].pop = i;
		}
	}
	
	
	
	int root = Build(vec);
	PostOrder(root);
	return 0;
} 
