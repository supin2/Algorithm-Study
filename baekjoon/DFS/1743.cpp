// 백준 1743번 : 음식물 피하기
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 100 + 1;
int N, M, K, cnt;
int area[MAX][MAX];
bool visited[MAX][MAX];

int dy[4] = {  0, 0, -1, 1 };
int dx[4] = { -1, 1,  0, 0 };

void DFS(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY <= 0 || nextY > N || nextX <= 0 || nextX > M) continue;
        if (area[nextY][nextX] == 0 || visited[nextY][nextX]) continue;
        visited[nextY][nextX] = true;
        cnt++;
        DFS(nextY, nextX);
    }
}


int main() {
    cin >> N >> M >> K;
    memset(area, 0, sizeof(area));
    memset(visited, false, sizeof(visited));
    int ret = -1;

    for (int i = 0; i < K; ++i) {
        int y, x;
        cin >> y >> x;
        area[y][x] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (area[i][j] == 1 && !visited[i][j]) {
                cnt++;
                DFS(i, j);
                ret = max(ret, cnt);
                cnt = 0;
            }
        }
    }
    cout << ret << '\n';

    return 0;
}