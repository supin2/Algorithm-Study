// 백준 18429번 : 근손실
#include <bits/stdc++.h>

using namespace std;

int N, K, W = 500, ans;
int weight[51];
bool selected[51];


void dfs(int cnt) {
    if (cnt == N) {
        ans++;
    }
    for (int i = 0; i < N; i++) {
        if (selected[i]) {
            continue;
        } else {
            if (W + weight[i] >= 500) {
                selected[i] = true;
                W += weight[i];
                dfs(cnt + 1);
                selected[i] = false;
                W -= weight[i];
            } else {
                selected[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> weight[i];
        weight[i] -= K;
    }
    dfs(0);
    cout << ans;
    return 0;
}