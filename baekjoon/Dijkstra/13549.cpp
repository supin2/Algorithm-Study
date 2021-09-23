// 백준 13549번 : 숨바꼭질 3
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int dist[100001];
int N, K;

int dt[2] = { 1, -1 };

void dijkstra(int start) {
    int nextPos, ntime;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int time = pq.top().first;
        int nowPos = pq.top().second;
        pq.pop();

        if (time > dist[nowPos]) {
            continue;
        }
        for (int i = 0; i < 3; i++) {
            if (i == 2) {
                nextPos = nowPos * 2;
                ntime = time;
            } else {
                nextPos = nowPos + dt[i];
                ntime = time + 1;
            }
            if (nextPos < 0 || nextPos > 100000) {
                continue;
            }

            if (dist[nextPos] > ntime) {
                dist[nextPos] = ntime;
                pq.push(make_pair(ntime, nextPos));
            }
        }
    }
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < 100001; i++) {
        dist[i] = INF;
    }
    dijkstra(N);
    
    cout << dist[K] << '\n';
    return 0;
}