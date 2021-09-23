// 백준 9205번 : 맥주 마시면서 걸어가기
#include <iostream>

using namespace std;

#define INF 987654321

bool calculate(pair<int, int> p[102], int x, int y) {
    if (abs(p[x].first - p[y].first) + abs(p[x].second - p[y].second) <= 1000) {
        return true;
    }
    return false;
}

int main() {
    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        pair<int, int> p[102];
        int dist[102][102];
        for (int i = 0; i < n + 2; i++) {
            cin >> p[i].first >> p[i].second;
        }
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) {
                dist[i][j] = INF;
            }
        }

        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) {
                if (i == j) {
                    continue;
                }
                if (calculate(p, i, j) == true) {
                    dist[i][j] = 1;
                }
            }
        }

        for (int k = 0; k < n + 2; k++) {
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < n + 2; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        if (dist[0][n + 1] != INF) {
            cout << "happy" << '\n';
        } else {
            cout << "sad" << '\n';
        }
    }
    return 0;
}