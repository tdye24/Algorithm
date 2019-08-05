#include<bits/stdc++.h>
using namespace std;
int main() {
	int A1, A2, A3, B1, B2, B3;
	scanf("%d.%d.%d", &A1, &A2, &A3);
	scanf("%d.%d.%d", &B1, &B2, &B3);
	int A3_ = (A3+B3)%29;
	int A2_ = ((A3+B3)/29 + A2 + B2)%17;
	int A1_ = ((A3+B3)/29 + A2 + B2)/17 + A1 + B1;
	printf("%d.%d.%d", A1_, A2_, A3_);
} 
