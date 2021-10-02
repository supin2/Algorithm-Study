// 백준 17265번 : 나의 인생에는 수학과 함께
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int N;
char map[5][5];
bool visited[5][5];
int D[2][2] = {{ 0, 1 }, { 1, 0 }};
int maxNum = -987654321, minNum = 987654321;

void dfs(int y, int x, int sum) {
    if (y == N - 1 && x == N - 1) {
        maxNum = max(maxNum, sum);
        minNum = min(minNum, sum);
        return;
    }

    for (int i = 0; i < 2; i++) {
        int nextY = y + D[i][0];
        int nextX = x + D[i][1];

        if (nextY >= N || nextX >= N || visited[nextY][nextX]) {
            continue;
        }
        visited[nextY][nextX] = true;
        if (map[y][x] == '+') {
            dfs(nextY, nextX, sum + (map[nextY][nextX] - '0'));
        } else if (map[y][x] == '-') {
            dfs(nextY, nextX, sum - (map[nextY][nextX] - '0'));
        } else if (map[y][x] == '*') {
            dfs(nextY, nextX, sum * (map[nextY][nextX] - '0'));
        } else {
            dfs(nextY, nextX, sum);
        }
        visited[nextY][nextX] = false;
    }
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    dfs(0, 0, map[0][0] - '0');

    cout << maxNum << ' ' << minNum;
    return 0;
}