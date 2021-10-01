// 백준 14267번 : 회사 문화 1
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> org[100001];
int dp[100001];

void dfs(int node) {
    for (int i = 0; i < org[node].size(); i++) {
        int next = org[node][i];
        dp[next] += dp[node];
        dfs(next);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int r;
    for (int i = 0; i < n; i++) {
        int root;
        cin >> root;
        if (root == -1) {
            r = i + 1;
            continue;
        } else {
            org[root].push_back(i + 1);
        }
    }
    
    for (int i = 0; i < m; i++) {
        int node, score;
        cin >> node >> score;
        dp[node] += score;
    }
    dfs(r);
    
    for (int i = 0; i < n; i++) {
        cout << dp[i + 1] << ' ';
    }
    
    return 0;
}