#include<bits/stdc++.h>

using namespace std;

int N;
int ans[1010];
int ansNum;

struct Book {
	int id;
	char title[84];
	char author[84];
	char keywords[55];
	char publisher[84];
	int year;
} books[10010]; 

void printAns() {
	if(ansNum == 0) {
		printf("Not Found\n");
		return;
	}
	sort(ans, ans+ansNum);
	for(int i=0; i<ansNum; i++) {
		printf("%07d\n", ans[i]);
	}
	ansNum = 0;
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &books[i].id);
		getchar();
		cin.getline(books[i].title, 84);
		cin.getline(books[i].author, 84);
		cin.getline(books[i].keywords, 55);
		cin.getline(books[i].publisher, 84);
		scanf("%d", &books[i].year);
	} 
	int M;
	scanf("%d", &M);
	int queryID;
	char queryStr[84];
	int queryYear;
	while(M--) {
		scanf("%d: ", &queryID);
		switch(queryID) {
			case 1: {
				cin.getline(queryStr, 84);
				for(int i=0; i<N; i++) {
					if(!strcmp(queryStr, books[i].title)) {
						ans[ansNum++] = books[i].id;
					}
				}
				printf("1: %s\n", queryStr);
				printAns();
				break;
			}
			case 2: {
				cin.getline(queryStr, 84);
				for(int i=0; i<N; i++) {
					if(!strcmp(queryStr, books[i].author)) {
						ans[ansNum++] = books[i].id;
					}
				}
				printf("2: %s\n", queryStr);
				printAns();
				break;
			}
			case 3: {
				cin.getline(queryStr, 84);
				for(int i=0; i<N; i++) {
					if(strstr(books[i].keywords, queryStr)) {
						ans[ansNum++] = books[i].id;
					}
				}
				printf("3: %s\n", queryStr);
				printAns();
				break;
			}
			case 4: {
				cin.getline(queryStr, 84);
				for(int i=0; i<N; i++) {
					if(!strcmp(queryStr, books[i].publisher)) {
						ans[ansNum++] = books[i].id;
					}
				}
				printf("4: %s\n", queryStr);
				printAns();
				break;
			} 
			case 5: {
				scanf("%d", &queryYear);
				for(int i=0; i<N; i++) {
					if(queryYear == books[i].year) {
						ans[ansNum++] = books[i].id;
					}
				}
				printf("5: %04d\n", queryYear);
				printAns();
				break;
			}
		} 
	}
	return 0;
} 
