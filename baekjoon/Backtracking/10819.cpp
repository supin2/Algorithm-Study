// 백준 10819번 : 차이를 최대로
#include <iostream>
#include <algorithm>

using namespace std;

int N, ans = -987654321;
int arr[9], ret[9];
bool visited[9] = { false, };

void dfs(int cnt) {
    if (cnt == N) {
        int sum = 0;
        for (int i = 0; i < N - 1; i++) {
            sum += abs(ret[i] - ret[i + 1]);
        }
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        ret[cnt] = arr[i];
        dfs(cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    dfs(0);

    cout << ans;
    return 0;
}