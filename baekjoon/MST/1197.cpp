// 백준 1197번 : 최소 스패닝 트리
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;

bool cmp(vector<int> v1, vector<int> v2) {
    return v1[2] < v2[2];
}

int getParent(int parent[], int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = getParent(parent, parent[x]);
}

bool Find(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);

    if (a == b) {
        return true;
    } else {
        return false;
    }
}

void Union(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);

    if (a < b) {
        parent[a] = b;
    } else {
        parent[b] = a;
    }
}

int main() {
    int V, E, ans = 0;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        vector<int> tmp(3);
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);

    int parent[10001];

    for (int i = 0; i <= V; i++) {
        parent[i] = i;
    }
    for (auto c : v) {
        if (Find(parent, c[0], c[1]) == false) {
            ans += c[2];
            Union(parent, c[0], c[1]);
        }
    }

    cout << ans;
    return 0;
}