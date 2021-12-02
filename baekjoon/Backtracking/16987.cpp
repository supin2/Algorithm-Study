// 백준 16987번 : 계란으로 계란치기
#include <bits/stdc++.h>

using namespace std;

int N, ans = -1;
vector<pair<int, int>> v;

void dfs(int idx) {
    if (idx == N) {
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].first <= 0) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }
    if (v[idx].first <= 0) {
        dfs(idx + 1);
    } else {
        bool broken = false;
        for (int j = 0; j < v.size(); j++) {
            if (j == idx || v[j].first <= 0) {
                continue;
            }
            broken = true;
            v[j].first -= v[idx].second;
            v[idx].first -= v[j].second;
            dfs(idx + 1);
            v[j].first += v[idx].second;
            v[idx].first += v[j].second;
        }
        if (!broken) {
            dfs(N);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    dfs(0);
    cout << ans;
    return 0;
}