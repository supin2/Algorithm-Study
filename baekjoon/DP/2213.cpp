// 백준 2213번 : 트리의 독립집합
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> v[10001];
int cost[10001];
int dp[10001][2]; // 0 : 독립집합, 1 : 아님
bool visited[10001];
vector<int> ans;

int n;

void dfs(int node) {
    visited[node] = true;
    dp[node][0] = cost[node];
    dp[node][1] = 0;

    for (int next : v[node]) {
        if (visited[next]) {
            continue;
        }
        dfs(next);
        dp[node][0] += dp[next][1];
        dp[node][1] += max(dp[next][0], dp[next][1]);
    }
}

void track(int now, bool selected) {
    visited[now] = true;
    if (selected) {
        ans.push_back(now);

        for (int next : v[now]) {
            if (visited[next]) {
                continue;
            }
            track(next, false);
        }
    } else {
        for (int next : v[now]) {
            if (visited[next]) {
                continue;
            }
            if (dp[next][0] >= dp[next][1]) {
                track(next, true);
            } else {
                track(next, false);
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int ret1 = dp[1][0];
    int ret2 = dp[1][1];

    memset(visited, false, sizeof(visited));
    if (ret1 > ret2) {
        track(1, true);
    } else {
        track(1, false);
    }
    sort(ans.begin(), ans.end());

    cout << max(dp[1][0], dp[1][1]) << '\n';
    for (int a : ans) {
        cout << a << ' ';
    }
    return 0;
}