// 백준 1753번 : 최단경로
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int dist[20001];
vector<pair<int, int>> road[200001];

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dist[current] < distance) {
            continue;
        }
        for (int i = 0; i < road[current].size(); i++) {
            int next = road[current][i].first;
            int nextDistance = distance + road[current][i].second;

            if (nextDistance < dist[next]) {
                dist[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main() {
    int V, E, K;

    cin >> V >> E >> K;

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }

    while(E--) {
        int u, v, w;
        cin >> u >> v >> w;
        road[u].push_back(make_pair(v, w));
    }

    dijkstra(K);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << "INF" << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }
    return 0;
}