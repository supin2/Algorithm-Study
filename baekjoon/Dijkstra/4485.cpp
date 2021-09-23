// 백준 4485번 : 녹색 옷 입은 애가 젤다지?
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define INF 987654321

int N;
int map[126][126];
int visited[126][126];
int dist[126][126];

int dy[4] = { 0,  0, -1, 1 };
int dx[4] = { 1, -1,  0, 0 };

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    visited[0][0] = true;

    while(!pq.empty()) {
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            int nextCost = cost + map[nextY][nextX];

            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N) {
                continue;
            }
            if (visited[nextY][nextX] == false && dist[nextY][nextX] > nextCost) {
                dist[nextY][nextX] = nextCost;
                visited[nextY][nextX] = true;
                pq.push(make_pair(-nextCost, make_pair(nextY, nextX)));
            }
        }
    }
}

int main() {
    int num = 1;
    while (true) {
        cin >> N;

        if (N == 0) {
            break;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                dist[i][j] = INF;
            }
        }
        memset(visited, false, sizeof(visited));
        dijkstra();

        cout << "Problem " << num++ << ": " << map[0][0] + dist[N - 1][N - 1] << '\n';
    }
    return 0;
}