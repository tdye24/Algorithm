#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
struct Node {
	int id, data, nextid;
} nodes[maxn];
int book[maxn];
int N, id, data, nextid, start;
vector<Node> old;
vector<Node> new_;
int main() {
	cin >> start >> N;
	for(int i=0; i<N; i++) {
		cin >> id >> data >> nextid;
		nodes[id].id = id; 
		nodes[id].data = data;
		nodes[id].nextid = nextid;
	}
		
	
	id = start;
	while(id != -1) {
		if(book[abs(nodes[id].data)] == 0) {
			if(old.size() != 0) {
				//cout << old[old.size()-1].nextid;
				old[old.size()-1].nextid = id;	
			}
				
			old.push_back(nodes[id]);
			book[abs(nodes[id].data)]++;
		} else {
			if(new_.size() != 0) {
				//cout << new_[new_.size()-1].nextid;
				new_[new_.size()-1].nextid = id;
			}
					 		
			new_.push_back(nodes[id]);
		}	
		id = nodes[id].nextid;
	}
	if(!old.empty() && old[old.size()-1].nextid != -1) //该处发生段错误，因为不能判断old和new是否为空，所以要提前判断一下 
		old[old.size()-1].nextid = -1;
	if(!new_.empty() && new_[new_.size()-1].nextid != -1)
		new_[new_.size()-1].nextid = -1;
	for(vector<Node>::iterator it=old.begin(); it!=old.end(); it++) 
		if((*it).nextid != -1)
			printf("%05d %d %05d\n", (*it).id, (*it).data, (*it).nextid);
		else
			printf("%05d %d -1\n", (*it).id, (*it).data);
	for(vector<Node>::iterator it=new_.begin(); it!=new_.end(); it++) {
		if((*it).nextid != -1)
			printf("%05d %d %05d\n", (*it).id, (*it).data, (*it).nextid);
		else
			printf("%05d %d -1\n", (*it).id, (*it).data);
	}
	return 0;
} 
