// 백준 2458번 : 키 순서
#include <iostream>

using namespace std;

#define INF 987

int main() {
    int N, M, ans = 0;
    int dist[501][501];
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                continue;
            }
            if (dist[i][j] != INF || dist[j][i] != INF) {
                cnt++;
            }
        }
        if (cnt == N - 1) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}