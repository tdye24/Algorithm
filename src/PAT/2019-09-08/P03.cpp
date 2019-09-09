#include<bits/stdc++.h>
using namespace std;
const int maxn = 24;
int N;
struct Node {
    string data;
    int left;
    int right;
} nodes[maxn];

bool isRoot[maxn] = {false};

int findRoot() {
    for(int i=1; i<=N; i++) {
        if(!isRoot[i])
            return i;
    }
    return -1;
}

void Postorder(int root) {
    cout << "(";
    if(nodes[root].left != -1)
        Postorder(nodes[root].left);
    if(nodes[root].left == -1 && nodes[root].right != -1) {
        cout << nodes[root].data;
        Postorder(nodes[root].right);
        cout <<")";
        return;
    }
    if(nodes[root].left != -1 && nodes[root].right != -1)
        Postorder(nodes[root].right);
    cout << nodes[root].data;
    cout <<")";
    return;
}

int main() {
    cin >> N;
    string data;
    int left, right;
    for(int i=1; i<=N; i++) {
        cin >> data >> left >> right;
        isRoot[left] = true;
        isRoot[right] = true;
        nodes[i].data = data;
        nodes[i].left = left;
        nodes[i].right = right;
    }
    Postorder(findRoot());
    system("pause");
    return 0;
}