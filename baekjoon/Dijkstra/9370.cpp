// 백준 9370번 : 미확인 도착지
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 987654321

vector<pair<int, int>> road[2001];

vector<int> dijkstra(int start) {
    vector<int> dist(2001, INF);
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
    return dist;
}

int main() {
    int Case;
    cin >> Case;

    while (Case--) {
        int n, m, t, s, g, h;
        cin >> n >> m >> t >> s >> g >> h;

        for (int i = 1; i <= n; i++) {
            road[i].clear();
        }
        while (m--) {
            int a, b, d;
            cin >> a >> b >> d;
            road[a].push_back(make_pair(b, d));
            road[b].push_back(make_pair(a, d));
        }
        vector<int> candidate;
        while (t--) {
            int x;
            cin >> x;
            candidate.push_back(x);
        }
        sort(candidate.begin(), candidate.end());

        vector<int> temp1 = dijkstra(s);
        vector<int> temp2 = dijkstra(g);
        vector<int> temp3 = dijkstra(h);

        int route1 = temp1[g] + temp2[h]; // s->g->h
        int route2 = temp1[h] + temp3[g]; // s->h->g
        
        vector<int> answer;
        for (int i = 0; i < candidate.size(); i++) {
            if (temp1[candidate[i]] == route1 + temp3[candidate[i]] || temp1[candidate[i]] == route2 + temp2[candidate[i]]) {
                answer.push_back(candidate[i]);
            }
        }
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}