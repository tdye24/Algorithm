#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
 
struct Station {
    double p, d;
} stations[510];
 
bool cmp(Station s1, Station s2) {
    return s1.d < s2.d;
}
 
int main() {
    double tank, d, d_avg;
    int n;
    // 输入
    cin >> tank >> d >> d_avg >> n;
    for (int i = 0; i < n; i ++) {
        cin >> stations[i].p >> stations[i].d;
    }
    // 排序
    sort(stations, stations+n, cmp);
    // 如果起始点没有加油站，则直接输出并结束程序
    if (stations[0].d != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    double ans = 0;
    double one_dis = tank * d_avg; // 满油能走的最长距离
    double current_tank = 0; // 记录当前剩余油量
    int pos = 0; // 记录当前在的加油站的编号
    while (1) {
        int target = pos; // 记录下个要到达的加油站索引号
        double tmp = stations[pos+1].p; // 记录最小油价
        double farrest = current_tank * d_avg + stations[pos].d; // 记录当前油量能走到的最大距离
        // 寻找到行程内比当前加油站油价低的第一个加油站，如果找不到，就找油价最低的加油站
        for (int i = pos+1; i < n; i ++) {
            if (stations[i].d > stations[pos].d+one_dis) break;
            if (stations[i].p < stations[pos].p) {
                target = i;
                break;
            }
            if (stations[i].p <= tmp) {
                target = i;
                tmp = stations[i].p;
            }
        }
        // 如果当前加油站后面没有加油站或者后面的加油站到达不了
        if (target == pos) {
            // 能到达终点
            if (stations[pos].d + one_dis >= d) {
                if (farrest < d) {
                    ans += stations[pos].p * (d-farrest) / d_avg;
                }
                printf("%.2lf\n",ans);
            }
            // 不能到达终点
            else {
                printf("The maximum travel distance = %.2lf", stations[pos].d+one_dis);
            }
            break;
        }
        // 如果目标加油站的油价比当前加油站油价高
        if (stations[target].p >= stations[pos].p) {
            if (stations[pos].d + one_dis >= d) {
                if (farrest < d) {
                    ans += stations[pos].p * (d-farrest) / d_avg;
                }
                printf("%.2lf\n",ans);
                break;
            }
            else {
                ans += stations[pos].p * (tank-current_tank);
                current_tank = tank - (stations[target].d-stations[pos].d) / d_avg;
                pos = target;
            }
        }
        // 其他情况进入下一个加油站
        else {
            if (farrest < stations[target].d) {
                ans += stations[pos].p * (stations[target].d-farrest) / d_avg;
                current_tank += (stations[target].d-farrest) / d_avg;
            }
            current_tank -= (stations[target].d-stations[pos].d) / d_avg;
            pos = target;
        }
    }
    return 0;
}
