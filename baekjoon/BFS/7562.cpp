// 백준 7562번 : 나이트의 이동
#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 301;

int N, I;
int startX, startY, endX, endY;
int cache[MAX][MAX];
bool visited[MAX][MAX];

int dy[8] = { -2, -1, 2, 1,  2,  1, -2, -1 };
int dx[8] = {  1,  2, 1, 2, -1, -2, -1, -2 };

void init() {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            cache[i][j] = INT_MAX;
        }
    }
}

int BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    cache[y][x] = 0;
    visited[y][x] = true;

    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        if (nowY == endY && nowX == endX) {
            return cache[nowY][nowX];
        }

        for (int i = 0; i < 8; ++i) {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if (0 <= nextY && nextY < I && 0 <= nextX && nextX < I) {
                if (!visited[nextY][nextX]) {
                    q.push(make_pair(nextY, nextX));
                    visited[nextY][nextX] = true;
                    cache[nextY][nextX] = min(cache[nextY][nextX], cache[nowY][nowX] + 1);
                }
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> I;
        cin >> startY >> startX;
        cin >> endY >> endX;

        memset(visited, false, sizeof(visited));
        init();
        cout << BFS(startY, startX) << '\n';
    }
    return 0;
}