#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321

vector<pair<int, int>> v[20001];

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if (dist[now] < cost) {
            continue;
        }
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i].first;
            int nCost = cost + v[now][i].second;
            
            if (dist[next] > nCost) {
                dist[next] = nCost;
                pq.push(make_pair(nCost, next));
            }
        }
    }
    return dist;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for (auto e : edge) {
        v[e[0]].push_back(make_pair(e[1], 1));
        v[e[1]].push_back(make_pair(e[0], 1));
    }
    vector<int> ret = dijkstra(1, n);
    
    for (int i = 0; i <= n; i++) {
        if (ret[i] == INF) {
            ret[i] = -1;
        }
    }
    sort(ret.begin(), ret.end());
    int maxNum = *max_element(ret.begin(), ret.end());
    answer = ret.end() - lower_bound(ret.begin(), ret.end(), maxNum);
    
    return answer;
}