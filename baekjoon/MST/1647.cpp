// 백준 1647번 : 도시 분할 계획
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
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

bool Find(int parent[], int a, int b) {
    return getParent(parent, a) == getParent(parent, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, ans = 0;
    int parent[100001];
    vector<pair<int, pair<int, int>>> road;
    vector<int> ret;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        road.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(road.begin(), road.end());

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (auto r : road) {
        int from = r.second.first;
        int to = r.second.second;
        int cost = r.first;
        if (!Find(parent, from, to)) {
            Union(parent, from, to);
            ret.push_back(cost);
        }
    }
    for (int i = 0; i < ret.size() - 1; i++) {
        ans += ret[i];
    }
    cout << ans;
    return 0;
}