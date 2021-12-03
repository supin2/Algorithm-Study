// 백준 16922번 : 로마 숫자 만들기
#include <bits/stdc++.h>

using namespace std;

int N, ans;
bool visited[1001];
int alpha[4] = { 1, 5, 10, 50 };

void dfs(int cnt, int idx, int sum) {
    if (cnt == N) {
        if (!visited[sum]) {
            ans++;
            visited[sum] = true;
        }
        return;
    }
    for (int i = idx; i < 4; i++) {
        dfs(cnt + 1, i, sum + alpha[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}