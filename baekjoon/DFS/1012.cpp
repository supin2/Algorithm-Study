// 백준 1012번 : 유기농 배추
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 50 + 1;
int T, M, N, K, cnt;
int farm[MAX][MAX];
bool visited[MAX][MAX];

int dy[4] = { 0,  0, -1, 1 };
int dx[4] = { 1, -1,  0, 0 };

void DFS(int y, int x) {
    if (visited[y][x]) {
        return;
    }
    visited[y][x] = true;
    for (int i = 0; i < 4; ++i) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
        if (farm[nextY][nextX] != 1 || visited[nextY][nextX]) continue;
        DFS(nextY, nextX);
    }
}


int main() {
    cin >> T;

    while (T--) {
        memset(farm, 0, sizeof(farm));
        memset(visited, false, sizeof(visited));
        cin >> M >> N >> K;

        while (K--) {
            int y, x;
            cin >> y >> x;
            farm[x][y] = 1;
        }
        cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (farm[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    DFS(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}