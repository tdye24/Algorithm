#include<bits/stdc++.h>
using namespace std;
/*
*PAT1056. Mice and Rice(25)[Queue的用法]
*/
struct node {
    int weight, index, rank, index0;
};

bool cmp(node a, node b) {
    return a.index0 < b.index0;
}

int main() {
    int n, g, num;
    scanf("%d%d", &n, &g);
    vector<int> v(n); //重量
    vector<node> w(n); //存放老鼠info
    for(int i=0; i<n; i++) 
        scanf("%d", &v[i]); //重量
    for(int i=0; i<n; i++) { //num老鼠标号，第几个老鼠
        scanf("%d", &num);
        w[i].weight = v[num];
        w[i].index0 = num; //排序前的顺序
        w[i].index = i; //排序后的顺序
    }
    queue<node> q;
    for(int i=0; i<n; i++) 
        q.push(w[i]);
    while(!q.empty()) {
        int size = q.size();
        if(size == 1) {
            node temp = q.front();
            w[temp.index].rank = 1;
            break;
        }
        int group = size / g;
        if(size % g != 0) 
            group += 1;
        node maxnode;
        int maxn = -1, cnt = 0;
        for(int i=0; i<size; i++) {
            node temp = q.front();
            w[temp.index].rank = group + 1;
            q.pop();
            cnt++;
            if(temp.weight > maxn) {
                maxn = temp.weight;
                maxnode = temp;
            }
            if(cnt == g || i == size - 1) {
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }
    sort(w.begin(), w.end(), cmp);
    for(int i=0; i<n; i++) {
        if(i != 0)  printf(" ");
        printf("%d", w[i].rank);
    }
    return 0;
}