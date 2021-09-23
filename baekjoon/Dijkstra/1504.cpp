// 백준 1504번 : 특정한 최단 경로
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int N, E;
vector<pair<int, int>> v[801];

vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({ 0, start });

    while(!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) {
            continue;
        }
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i].first;
            int nCost = v[now][i].second + cost;

            if (nCost < dist[next]) {
                dist[next] = nCost;
                pq.push({ nCost, next });
            }
        }
    }
    return dist;
}

int main() {
    int ans = 0;
    cin >> N >> E;

    while(E--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }
    int v1, v2;
    cin >> v1 >> v2;

    vector<int> temp1 = dijkstra(1);
    vector<int> temp2 = dijkstra(v1);
    vector<int> temp3 = dijkstra(v2);

    ans = min(temp1[v1] + temp2[v2] + temp3[N], temp1[v2] + temp3[v1] + temp2[N]);

    if (ans >= INF || ans < 0) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}