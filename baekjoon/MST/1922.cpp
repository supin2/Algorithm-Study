// 백준 1922번 : 네트워크 연결
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2) {
    return v1[2] < v2[2];
}

int getParent(int parent[], int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = getParent(parent, parent[x]);
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

bool Find(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    if (a == b) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int N, M, ans = 0;
    cin >> N >> M;

    int parent[1001];
    vector<vector<int>> v;
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        vector<int> tmp(3);
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);

    for (auto c : v) {
        if (Find(parent, c[0], c[1]) == false) {
            ans += c[2];
            Union(parent, c[0], c[1]);
        }
    }
    cout << ans;
    return 0;
}