// 백준 1939번 : 중량제한
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int N, M;
vector<pair<int, int>> road[100001];

vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) {
            continue;
        }
        for (int i = 0; i < road[now].size(); i++) {
            int next = road[now][i].first;
            int nCost = road[now][i].second + cost;

            if (dist[next] > nCost) {
                dist[next] = nCost;
                pq.push(make_pair(nCost, next));
            }
        }
    }
}


int main() {
    cin >> N >> M;
    while (M--) {
        int A, B, C;
        cin >> A >> B >> C;
        road[A].push_back(make_pair(B, C));
        road[B].push_back(make_pair(A, C));
    }
    int s, e;
    cin >> s >> e;
    vector<int> v = dijkstra(s);

    cout << v[e] << '\n';

    return 0;
}