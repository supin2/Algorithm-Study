// 백준 11725번 : 트리의 부모 찾기
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001];
int parent[100001];

void dfs(int node) {
    if (v[node].empty()) {
        return;
    }

    for (int i = 0; i < v[node].size(); i++) {
        int next = v[node][i];
        if (!parent[next]) {
            parent[next] = node;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    parent[1] = 1;
    dfs(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}