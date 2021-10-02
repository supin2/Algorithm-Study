// 백준 16174번 : 점프왕 쩰리 (Large)
#include <iostream>
#include <cstring>

using namespace std;

int N;
int area[65][65];
bool visited[65][65];
int D[2][2] = {{ 0, 1 }, { 1, 0 }};

bool dfs(int y, int x){  
    if (y == N - 1 && x == N - 1) {
        return true;
    }

    for (int i = 0; i < 2; i++) {
        int nextY = y + D[i][0] * (area[y][x]);
        int nextX = x + D[i][1] * (area[y][x]);

        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || visited[nextY][nextX]) {
            continue;
        }
        visited[nextY][nextX] = true;
        bool flag = dfs(nextY, nextX);
        if (flag) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> area[i][j];
        }
    }
    memset(visited, false, sizeof(visited));

    bool ret = dfs(0, 0);
    if (ret) {
        cout << "HaruHaru";
    } else {
        cout << "Hing";
    }
    return 0;
}