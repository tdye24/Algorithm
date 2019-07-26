#include<bits/stdc++.h> 

using namespace std;

struct Stu {
	int ID;
	int C;
	int M;
	int E;
	int A;
};

void getRank(vector<Stu> vec, int ID);

vector<Stu> vec; 

int main() {
	int N, M;
	int ID;
	int CG, MG, EG;
	cin >> N >> M;
	Stu stu;
	for(int i=0; i<N; i++) {
		cin >> ID;
		stu.ID = ID;
		cin >> CG;
		stu.C = CG;
		cin >> MG;
		stu.M = MG;
		cin >> EG;
		stu.E = EG;
		stu.A = (CG+MG+EG)/3;
		vec.push_back(stu);
	}
	
	for(int i=0; i<M; i++) {
		cin >> ID;
		getRank(vec, ID);
	}
		
	return 0;
}

void getRank(vector<Stu> vec, int ID) {
	int Crank = 1;
	int Mrank = 1;
	int Erank = 1;
	int Arank = 1;
	Stu currentStu;
	currentStu.ID = -1;
	for(int i=0; i<vec.size(); i++) {
		if(ID == vec[i].ID) {
			currentStu = vec[i];
			break;
		}
	}
	if(currentStu.ID == -1) {
		cout << "N/A" << endl;
		return ;
	}
		
	for(int i=0; i<vec.size(); i++) {
		if(vec[i].C > currentStu.C) 
			Crank ++;
	}
	for(int i=0; i<vec.size(); i++) {
		if(vec[i].M > currentStu.M) 
			Mrank ++;
	}
	for(int i=0; i<vec.size(); i++) {
		if(vec[i].E > currentStu.E) 
			Erank ++;
	}
	for(int i=0; i<vec.size(); i++) {
		if(vec[i].A > currentStu.A) 
			Arank ++;
	}
	
	int best = min(Crank, min(Mrank, min(Erank, Arank)));
	if(Arank == best) {
		cout << best << " " << "A" << endl;
		return ;
	}
	if(Crank == best) {
		cout << best << " " << "C" << endl;
		return ;
	}
	if(Mrank == best) {
		cout << best << " " << "M" << endl;
		return ;
	}
	if(Erank == best) {
		cout << best << " " << "E" << endl;
		return ;
	}
}
