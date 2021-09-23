// 백준 10159번 : 저울
#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    int N, M;
    cin >> N >> M;
    int dist[101][101];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
    }

    while(M--) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                continue;
            }
            if (dist[i][j] != INF || dist[j][i] != INF) {
                sum++;
            }
        }
        ans.push_back(N - 1 - sum);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}