// 백준 12784번 : 인하니카 공화국
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define INF 987654321

int N, M;
vector<pair<int, int>> bridge[1001];
int dp[1001];

int dfs(int before, int now, int cost) {
    int &ret = dp[now];

    ret = 0;
    for (int i = 0; i < bridge[now].size(); i++) {
        int next = bridge[now][i].first;
        int nCost = bridge[now][i].second;

        if (dp[next] != -1) {
            continue;
        }
        ret += dfs(now, next, nCost);
    }
    if (ret == 0) { // Leaf
        return cost;
    }
    return ret > cost ? cost : ret;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            bridge[a].push_back(make_pair(b, c));
            bridge[b].push_back(make_pair(a, c));
        }
        memset(dp, -1, sizeof(dp));
        
        int ret = dfs(0, 1, INF);
        if (ret == INF) {
            cout << 0;
        } else {
            cout << ret;
        }
        cout << '\n';
        
        for (int i = 1; i <= N; i++) {
            bridge[i].clear();
        }
    }
    return 0;
}