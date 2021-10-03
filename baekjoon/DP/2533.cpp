// 백준 2533번 : 사회망 서비스(SNS)
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> v[1000001];
int dp[1000001][2];
bool visited[1000001];

void dfs(int node) {
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] = 1;

    for (auto next : v[node]) {
        if (visited[next]) {
            continue;
        }
        dfs(next);
        dp[node][0] += dp[next][1];
        dp[node][1] += min(dp[next][0], dp[next][1]);
    }
}

int main() {
    cin >> N;

    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));

    dfs(1);

    cout << min(dp[1][0], dp[1][1]);
    return 0;
}