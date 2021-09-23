// 백준 10971번 : 외판원 순회 2
#include <iostream>

using namespace std;

int N, ans = 987654321;
int arr[11][11];
bool visited[11] = { false, };

void dfs(int start, int now, int sum, int cnt) {
    if (cnt == N && now == start) {
        ans = min(ans, sum);
        return;
    }

    for (int next = 0; next < N; next++) {
        if (visited[next]) {
            continue;
        }
        if (now == next || arr[now][next] == 0) {
            continue;
        }
    
        visited[next] = true;
        dfs(start, next, sum + arr[now][next], cnt + 1);
        visited[next] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int row = 0; row < N; row++) {
        dfs(row, row, 0, 0);
    }
    cout << ans;
    return 0;
}