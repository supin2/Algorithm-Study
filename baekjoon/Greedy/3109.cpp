// 백준 3109번 : 빵집
#include <iostream>

using namespace std;

const int MAX = 10000;

int R, C, ans = 0;
string str[MAX];
bool visited[MAX][500] = { false, };

int dy[3] = { -1, 0, 1 }; // 대각 위, 가로, 대각 아래
int dx[3] = {  1, 1, 1 };

int DFS(int y, int x) {
    visited[y][x] = true;

    if (x == C - 1) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY >= 0 && nextY < R && nextX >= 0 && nextX < C) {
            if (!visited[nextY][nextX] && str[nextY][nextX] == '.') {
                if (DFS(nextY, nextX) == 1) return 1;
            }
        }
    }
    return 0;
}


int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> str[i];
    }
    for (int i = 0; i < R; i++) {
        ans += DFS(i, 0);
    }

    cout << ans << '\n';
    return 0;
}