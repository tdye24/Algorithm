#include<bits/stdc++.h>
using namespace std;
const char * One[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const char * Two[] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main() {
	int N; 
	scanf("%d", &N);
	getchar();
	char in[10];
	for(int i=0; i<N; i++) {
		cin.getline(in, 10);
		if('0'<=in[0] && in[0]<='9') {
			//Earth=>Mars 
			int num = 0, k = 1;
			int len = strlen(in);
			for(int j=len-1; j>=0; j--) {
				num += (in[j]-48)*k;
				k *= 10;
			}
			int a = num%13, b = num/13;
			if(b == 0) 
				cout << One[a] << endl; 
			else {
				if(a == 0) 
					printf("%s\n", Two[b-1]); 
				else 
					printf("%s %s\n", Two[b-1], One[a]); 
			}
			
				
		} else {
			//Mars=>Earth
			int len = strlen(in);
			if(len <= 4) {
				for(int i=0; i<13; i++) {
					if(strcmp(One[i], in) == 0){
						printf("%d\n", i);
						break;
					}
				}
				for(int i=0; i<12; i++) {
					if(strcmp(Two[i], in) == 0) {
						printf("%d\n", (i+1)*13);
						break;
					}
				}	
			} else {
				int a, b;
				char s1[6];
				char s2[6];
				for(int i=0; i<3; i++) {
					s1[i] = in[i];
				}
				for(int i=4; i<len; i++) {
					s2[i-4] = in[i];
				}
				
				for(int i=0; i<12; i++) {
					if(strcmp(Two[i], s1) == 0)
						a = i+1;
				}
				for(int i=0; i<13; i++) {
					if(strcmp(One[i], s2) == 0)
						b = i;
				}
				printf("%d\n", a*13+b);
			}
		}
	}
} 
/*
*超级坑的一个测试用例
*tam tret=13
*tam = 13
*13 = tam
*13 != tam tret 
/ 
