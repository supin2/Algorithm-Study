// 백준 15681번 : 트리와 쿼리
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> tree[100001];
int dp[100001];

int dfs(int now) {
    int &ret = dp[now];
    // if (ret != -1) {
    //     return ret;
    // }
    
    ret = 1;
    for (int i = 0; i < tree[now].size(); i++) {
        int next = tree[now][i];
        if (dp[next] != -1) {
            continue;
        }
        ret += dfs(next);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, R, Q;
    cin >> N >> R >> Q;
    
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dp[R] = dfs(R);
    
    while (Q--) {
        int node;
        cin >> node;
        cout << dp[node] << '\n';
    }
    return 0;
}