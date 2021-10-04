#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<pair<int, int>> v[51];
    vector<int> distance(N + 1, INF);
    
    for (vector<int> r : road) {
        v[r[0]].push_back(make_pair(r[1], r[2]));
        v[r[1]].push_back(make_pair(r[0], r[2]));
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[1] = 0;
    pq.push(make_pair(0, 1));
    
    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (distance[now] < cost) {
            continue;
        }
        for (auto a : v[now]) {
            int nCost = a.second + cost;
            int next = a.first;
            if (nCost < distance[next]) {
                distance[next] = nCost;
                pq.push(make_pair(nCost, next));
            }
        }
    }
    for (int i = 0; i < distance.size(); i++) {
        if (distance[i] <= K) {
            answer++;
        }
    }
    return answer;
}