// 백준 2211번 : 네트워크 복구
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int N, M;
vector<pair<int, int>> network[1001]; 
vector<int> dist(1001, INF);
int route[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    route[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[now] < cost) {
            continue;
        }
        for (int i = 0; i < network[now].size(); i++) {
            int next = network[now][i].first;
            int nCost = network[now][i].second + cost;

            if (dist[next] > nCost) {
                dist[next] = nCost;
                pq.push(make_pair(nCost, next));
                route[next] = now;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    while (M--) {
        int from, to, time;
        cin >> from >> to >> time;
        network[from].push_back(make_pair(to, time));
        network[to].push_back(make_pair(from, time));
    }
    dijkstra(1);
    
    cout << N - 1 << endl;
    for (int i = 2; i <= N; i++) {
        cout << route[i] << " " << i << '\n';
    }
    return 0;
}