#include <iostream>
#include <cstring>

using namespace std;

#define HOR 0 // 가로
#define VER 1 // 세로
#define DIA 2 // 대각선

int N, ans = 0;
int house[17][17];
int dir[3][2] = {{ 0, 1 }, { 1, 0 }, { 1, 1 }};

void dfs(int y, int x, int status) {
    if (y == N && x == N) {
        ans++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (status == HOR && i == VER || status == VER && i == HOR) {
            continue;
        }
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];

        if (nextY > N || nextX > N || house[nextY][nextX] == 1) {
            continue;
        }
        if (i == DIA && (house[y + 1][x] == 1 || house[y][x + 1] == 1)) {
            continue;
        }
        dfs(nextY, nextX, i);
    }
}

int main() {
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> house[i][j];
        }
    }
    dfs(1, 2, 0);

    cout << ans;
    return 0;
}