#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, c;
struct Student {
	int id;
	char name[10];
	int grade;
} stu[maxn]; 

bool cmp1(Student a, Student b) {
	return a.id < b.id;
}

bool cmp2(Student a, Student b) {
	if(!strcmp(a.name, b.name)) 
		return a.id < b.id;
	else
		return strcmp(a.name, b.name) < 0;
}

bool cmp3(Student a, Student b) {
	if(a.grade == b.grade)
		return a.id < b.id;
	else 
		return a.grade < b.grade;
}

int main() {
	scanf("%d%d", &n, &c);
	for(int i=0; i<n; i++) {
		scanf("%d %s %d", &stu[i].id, &stu[i].name, &stu[i].grade);
	}
	if(c == 1) 
		sort(stu, stu+n, cmp1);
	else if(c== 2)
		sort(stu, stu+n, cmp2);
	else
		sort(stu, stu+n, cmp3);
	
	for(int i=0; i<n; i++) 
	printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
}
