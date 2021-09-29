// 백준 5567번 : 결혼식
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[501];
int visited[501] = { false, };
int ans = 0;

void dfs(int now, int depth) {
    if (depth == 2) {
        return;
    }

    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now][i];
        visited[next] = true;
        dfs(next, depth + 1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited[1] = true;
    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            ans++;
        }
    }   
    cout << ans - 1;
    return 0;
}