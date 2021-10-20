// 백준 14442번 : 벽 부수고 이동하기 2
#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

struct point {
    int y, x, cnt, wall;
};

int N, M, K;
vector<string> v;
bool visited[1001][1001][11];
int D[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    queue<point> q;
    q.push({ 0, 0, 1, 0 });
    visited[0][0][0] = true;
    int ans = INF;

    while (!q.empty()) {
        int y = q.front().y, x = q.front().x;
        int cnt = q.front().cnt, wall = q.front().wall;
        q.pop();

        if (y == N - 1 && x == M - 1) {
            ans = min(ans, cnt);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nextY = y + D[i][0], nextX = x + D[i][1];
            int nWall = wall;

            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M || visited[nextY][nextX][nWall]) {
                continue;
            }
            if (v[nextY][nextX] == '1') {
                if (wall < K) {
                    nWall += 1;
                } else {
                    continue;
                }
            }
            visited[nextY][nextX][nWall] = true;
            q.push({ nextY, nextX, cnt + 1, nWall });
        }
    }
    cout << (ans == INF ? -1 : ans);
    return 0;
}