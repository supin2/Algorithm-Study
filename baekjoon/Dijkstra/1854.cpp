// 백준 1854번 : K번째 최단경로 찾기
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int n, m, k;
vector<pair<int, int>> road[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int> dist[1001];

void dijkstra(int start) {
    pq.push(make_pair(0, start));
    dist[1].push(0);

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for (int i = 0; i < road[now].size(); i++) {
            int next = road[now][i].first;
            int nCost = road[now][i].second + cost;

            if (dist[next].size() < k) {
                dist[next].push(nCost);
                pq.push(make_pair(nCost, next));
            } else if (dist[next].size() == k) {
                if (dist[next].top() > nCost) {
                    dist[next].pop();
                    dist[next].push(nCost);
                    pq.push(make_pair(nCost, next));
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        road[a].push_back(make_pair(b, c));
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++) {
        if (dist[i].size() < k) {
            cout << "-1" << '\n';
        } else {
            cout << dist[i].top() << '\n';
        }
    }
    return 0;
}