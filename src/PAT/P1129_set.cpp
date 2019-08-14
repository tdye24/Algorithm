#include <iostream>
#include <set>
using namespace std;
int book[50010];
struct node {
    int value, cnt;
    bool operator < (const node &a) const {
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};
int main() {
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<node> st;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i != 0) {
            printf("%d:", num);
            int tempCnt = 0;
            for(auto it = st.begin(); tempCnt < k && it != st.end(); it++) {
                printf(" %d", it->value);
                tempCnt++;
            }
            printf("\n");
        }
        auto it = st.find(node{num, book[num]});
        if (it != st.end()) st.erase(it);
        book[num]++;
        st.insert(node{num, book[num]});
    }
    return 0;
}
