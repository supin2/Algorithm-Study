// 백준 18352번 : 특정 거리의 도시 찾기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 987654321

int N, M, K, X;
vector<pair<int, int>> city[300001];

vector<int> dijkstra(int start) {
    vector<int> dist(300001, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[now] < cost) {
            continue;
        }
        for (int i = 0; i < city[now].size(); i++) {
            int next = city[now][i].first;
            int nCost = city[now][i].second + cost;

            if (dist[next] > nCost) {
                dist[next] = nCost;
                pq.push(make_pair(nCost, next));
            }
        }
    }
    return dist;
}

int main() {
    cin >> N >> M >> K >> X;

    while (M--) {
        int a, b;
        cin >> a >> b;
        city[a].push_back(make_pair(b, 1));
    }
    vector<int> temp = dijkstra(X);
    vector<int> ans;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (temp[i] >= INF || temp[i] < 0) {
            continue;
        } else if (temp[i] == K) {
            ans.push_back(i);
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << -1 << '\n';
    } else {
        sort(ans.begin(), ans.end());
        for (auto a : ans) {
            cout << a << '\n';
        }
    }
    return 0;
}