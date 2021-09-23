// 백준 2665번 : 미로 만들기
#include <iostream>
#include <queue>

using namespace std;

#define INF 987654321

int n;
int maze[51][51];
int dist[51][51];

int dy[4] = { 0,  0, -1, 1 };
int dx[4] = { 1, -1,  0, 0 };

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[0][0] = 0;
    pq.push(make_pair(0, make_pair(0, 0)));

    while(!pq.empty()) {
        int cnt = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        if (dist[y][x] < cnt) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
                continue;
            }
            int next_cnt = cnt + maze[nextY][nextX];
            if (dist[nextY][nextX] > next_cnt) {
                dist[nextY][nextX] = next_cnt;
                pq.push(make_pair(next_cnt, make_pair(nextY, nextX)));
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &maze[i][j]);
            maze[i][j] = (maze[i][j] == 0) ? 1 : 0;
            dist[i][j] = INF;
        }
    }
    dijkstra();

    cout << dist[n - 1][n - 1] << '\n';
    return 0;
}