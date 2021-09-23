// 백준 1916번 : 최소비용 구하기
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int dist[1001];
vector<pair<int, int>> bus[1001];

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        if (dist[vertex] < cost) {
            continue;
        }
        for (int i = 0; i < bus[vertex].size(); i++) {
            int next = bus[vertex][i].first;
            int nextDistance = cost + bus[vertex][i].second;

            if (dist[next] > nextDistance) {
                dist[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    while(M--) {
        int s, e, w;
        cin >> s >> e >> w;
        bus[s].push_back(make_pair(e, w));
    }
    int start, end;
    cin >> start >> end;

    dijkstra(start);

    cout << dist[end] << '\n';
    return 0;
}