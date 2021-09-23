// 백준 1238번 : 파티
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 100000

int N, M, X;
vector<pair<int, int>> map[1001];

vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dist[current] < distance) {
            continue;
        }
        for (int i = 0; i < map[current].size(); i++) {
            int next = map[current][i].first;
            int nextDistance = distance + map[current][i].second;

            if (nextDistance < dist[next]) {
                dist[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
    return dist;
}

int main() {
    int ans = -1;
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        map[x].push_back(make_pair(y, w));
    }

    for (int i = 1; i <= N; i++) {
        vector<int> v1 = dijkstra(i);
        vector<int> v2 = dijkstra(X);

        // if (v1[X] + v2[i] >= INF || v1[X] + v2[i] < 0) {
        //     continue;
        // }
        ans = max(ans, v1[X] + v2[i]);
    }
    cout << ans << '\n';
    return 0;
}