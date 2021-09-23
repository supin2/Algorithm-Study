// 백준 1389번
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 987654321

bool comp(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main() {
    int N, M;
    int dist[101][101];

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = dist[b][a] = 1;
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
    vector<pair<int, int>> ans;

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] != INF) {
                sum += dist[i][j];
            }
        }
        ans.push_back(make_pair(i, sum));
    }
    sort(ans.begin(), ans.end(), comp);

    cout << ans[0].first << endl;
    return 0;
}