// 백준 14053번 : 로봇 청소기
#include <iostream>

using namespace std;

#define MAX 51

int N, M, r, c, d, ans = 0;
int house[MAX][MAX];

int dy[4] = { -1, 0, 1,  0 }; // 북, 동, 남, 서
int dx[4] = {  0, 1, 0, -1 };

int back_dy[4] = { 1,  0, -1, 0 }; // 남, 서, 북, 동
int back_dx[4] = { 0, -1,  0, 1 };

void DFS(int y, int x, int d) {
    if (house[y][x] == 1) {
        return;
    }
    if (house[y][x] == 0) {
        ans++;
        house[y][x] = 2;
    }
    
    for (int i = 0; i < 4; ++i) {
        int nextDir = (d - 1 < 0 ? 3 : d - 1);
        int nextY = y + dy[nextDir];
        int nextX = x + dx[nextDir];

        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
        if (house[nextY][nextX] == 0) {
            DFS(nextY, nextX, nextDir);
            return;
        } else {
            d = nextDir;
        }
    }

    int beforeY = y + back_dy[d];
    int beforeX = x + back_dx[d];
    DFS(beforeY, beforeX, d);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> house[i][j];
        }
    }
    DFS(r, c, d);

    cout << ans << '\n';

    return 0;
}