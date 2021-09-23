// 백준 11779번 : 최소비용 구하기 2
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int n, m;
vector<pair<int, int>> v[1001];
int route[1001];

vector<int> dijkstra(int start) {
    vector<int> dist(1001, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

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

            if (dist[next] > nCost) {
                dist[next] = nCost;
                route[next] = now;
                pq.push(make_pair(nCost, next));
            }
        }
    }
    return dist;
}

int main() {
    cin >> n >> m;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    int s, e;
    cin >> s >> e;

    vector<int> ret = dijkstra(s);

    int tmp = e;

    vector<int> temp;
    while(tmp) {
        temp.push_back(tmp);
        tmp = route[tmp];
    }
    
    cout << ret[e] << '\n';
    cout << temp.size() << '\n';

    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << temp[i] << ' ';
    }
    
    return 0;
}