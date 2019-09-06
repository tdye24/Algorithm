#include<bits/stdc++.h>
using namespace std;
int main() {
    string week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int day, hour, minute;
    int i;
    for(i=0; i<min(s1.size(), s2.size()); i++) {
        if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') { //一定是<=G题目的坑 
            day = s1[i] - 'A';
            break;
        }
    }
    i++;
    for(; i<min(s1.size(), s2.size()); i++) {
        if(s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N') || isdigit(s1[i]))) {
            if(s1[i] >= 'A' && s1[i] <= 'N') 
                hour = s1[i] - 'A' + 10;
            if(isdigit(s1[i]))
                hour = s1[i] - '0';
            break;   
        }
    }
    for(i=0; i<min(s3.size(), s4.size()); i++) {
        if(s3[i] == s4[i] && isalpha(s3[i])) {
            minute = i;
            break;
        }  
    }
    printf("%s %02d:%02d", week[day].c_str(), hour, minute);
    return 0;
}
