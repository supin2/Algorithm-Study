// 백준 1717번 : 집합의 표현
#include <iostream>

using namespace std;

int n, m;
int parent[1000001];

int getParent(int parent[], int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = getParent(parent, parent[x]);
}

bool Find(int parent[], int a, int b) {
    return getParent(parent, a) == getParent(parent, b);
}

void Union(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);

    if (a < b) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 0) {
            Union(parent, a, b);
        } else {
            if (Find(parent, a, b)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}