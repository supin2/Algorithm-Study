// 백준 10282번 : 해킹
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

vector<pair<int, int>> computer[10001];

vector<int> dijkstra(int start) {
    vector<int> dist(10001, INF);
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
        for (int i = 0; i < computer[now].size(); i++) {
            int next = computer[now][i].first;
            int nCost = computer[now][i].second + cost;

            if (dist[next] > nCost) {
                dist[next] = nCost;
                pq.push(make_pair(nCost, next));
            }
        }
    }
    return dist;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, d, c;
        cin >> n >> d >> c;

        for (int i = 1; i <= n; i++) {
            computer[i].clear();
        }

        while (d--) {
            int a, b, s;
            cin >> a >> b >> s;
            computer[b].push_back(make_pair(a, s));
        }
        int cnt = 0, time = -1;
        vector<int> temp = dijkstra(c);

        for (int i = 1; i <= n; i++) {
            if (temp[i] != INF) {
                cnt++;
                time = max(temp[i], time);
            }
        }
        cout << cnt << " " << time << '\n';
    }
    return 0;
}