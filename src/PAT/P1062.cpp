#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct Person {
	int id, virtue, talent, call; //call->0:圣人，1:君子，2:愚人，3:小人 
	Person() {} //用以不经初始化的定义people[maxn] 
	Person(int _id, int _virtue, int _talent, int _call) {
		id = _id;
		virtue = _virtue;
		talent = _talent;
		call = _call;
	}
} people[maxn];
int N, L, H;

bool cmp(Person p1, Person p2) {
	if(p1.call != p2.call) 
		return p1.call < p2.call;
	if(p1.virtue + p1.talent != p2.virtue + p2.talent)
		return p1.virtue + p1.talent > p2.virtue + p2.talent;
	if(p1.virtue != p2.virtue)
		return p1.virtue > p2.virtue;
	return p1.id < p2.id;
}

int main() {
	cin >> N >> L >> H; 
	int M = 0, id, virtue, talent;
	while(N--) {
		cin >> id >> virtue >> talent;
		if(virtue >= L && talent >= L) {
			if(virtue >= H && talent >=H)
				people[M++] = Person(id, virtue, talent, 0);
			else if(virtue >= H)
				people[M++] = Person(id, virtue, talent, 1);
			else if(virtue < H && talent < H && virtue >= talent)
				people[M++] = Person(id, virtue, talent, 2);
			else
				people[M++] = Person(id, virtue, talent, 3);
		}		
	}
	sort(people, people+M, cmp);
	cout << M << endl;
	for(int i=0; i<M; i++)
		cout << people[i].id << " " << people[i].virtue << " " << people[i].talent << endl;
	return 0;
} 
