#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int dis[510], Time[510], e[510][510], w[510][510], dispre[510], Timepre[510], weight[510], NodeNum[510];
bool visit[510];
vector<int> dispath, Timepath, temppath;
int st, fin, minnode = inf;

void dfsdispath(int v) {
    dispath.push_back(v);
    if(v == st) return;
    dfsdispath(dispre[v]);
}

void dfsTimepath(int v) {
    Timepath.push_back(v);
    if(v == st) return;
    dfsTimepath(Timepre[v]);
}

int main() {
    fill(dis, dis + 510, inf);
    fill(Time, Time + 510, inf);
    fill(weight, weight + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf); //路径长度
    fill(w[0], w[0] + 510 * 510, inf); //时间
    int n, m;
    cin >> n >> m;
    int a, b, flag, len, t;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> flag >> len >> t;
        e[a][b] = len;
        w[a][b] = t;
        if(flag != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    cin >> st >> fin;
    dis[st] = 0;
    for(int i=0; i<n; i++) 
        dispre[i] = i;
    for(int i=0; i<n; i++) {
        int u = -1, minn = inf;
        for(int j=0; j<n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v=0; v<n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    dispre[v] = u;
                    weight[v] = weight[u] + w[u][v]; //时间
                } else if(e[u][v] + dis[u] == dis[v] && weight[v] > weight[u] + w[u][v]) {
                    weight[v] = weight[u] + w[u][v];
                    dispre[v] = u;
                }
            }
        }
    }
    dfsdispath(fin);
    Time[st] = 0;
    fill(visit, visit + 510, false); //再来一遍dijkstra算法
    for(int i=0; i<n; i++) {
        int u = -1, minn = inf;
        for(int j=0; j<n; j++) {
            if(visit[j] == false && minn > Time[j]) {
                u = j;
                minn = Time[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v=0; v<n; v++) {
            if(visit[v] == false && w[u][v] != inf) {
                if(w[u][v] + Time[u] < Time[v]) {
                    Time[v] = w[u][v] + Time[u];
                    Timepre[v] = u;
                    NodeNum[v] = NodeNum[u] + 1;
                } else if(w[u][v] + Time[u] == Time[v] && NodeNum[u] + 1 < NodeNum[v]) {
                    Timepre[v] = u;
                    NodeNum[v] = NodeNum[u] + 1;
                }
            }
        }
    }
    dfsTimepath(fin);
    printf("Distance = %d", dis[fin]);
    if(dispath == Timepath) {
        printf("; Time = %d: ", Time[fin]);
    } else {
        printf(": ");
        for(int i=dispath.size()-1; i>=0; i--) {
            printf("%d", dispath[i]);
            if(i != 0)  printf(" -> ");
        }
        printf("\nTime = %d: ", Time[fin]);
    }
    for(int i=Timepath.size()-1; i>=0; i--) {
        printf("%d", Timepath[i]);
        if(i != 0)  printf(" -> ");
    }
    return 0;
}