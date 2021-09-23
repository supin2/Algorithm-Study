// 백준 11404번 : 플로이드
#include <iostream>

using namespace std;

#define INF 987654321

int main() {
    int n, m;
    int route[101][101];

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            route[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int start, end, fee;
        cin >> start >> end >> fee;

        if (route[start][end] > fee) {
            route[start][end] = fee;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (route[i][j] > route[i][k] + route[k][j]) {
                    route[i][j] = route[i][k] + route[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (route[i][j] == INF || (i == j)) {
                cout << "0 ";
            } else {
                cout << route[i][j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}