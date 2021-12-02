// 백준 16198번 : 에너지 모으기
#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int ans;

void dfs(int sum) {
    if (v.size() == 2) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 1; i < v.size() - 1; i++) {
        int energy = v[i - 1] * v[i + 1];
        int tmp = v[i];
        v.erase(v.begin() + i);
        dfs(sum + energy);
        v.insert(v.begin() + i, tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    dfs(0);
    cout << ans;
    return 0;
}