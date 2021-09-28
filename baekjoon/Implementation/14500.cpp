// 백준 14500번 : 테크로미노
#include <iostream>
#include <cstring>

using namespace std;

int N, M, ans = -1;
int paper[501][501];
int visited[501][501];

int dir[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

void checkTshape(int y, int x) {
    if (y > 0 && x > 0 && x < M - 1) {
        ans = max(ans, paper[y][x] + paper[y - 1][x] + paper[y][x + 1] + paper[y][x - 1]); // ㅗ
    }
    if (y > 0 && y < N - 1 && x < M - 1) {
        ans = max(ans, paper[y][x] + paper[y - 1][x] + paper[y][x + 1] + paper[y + 1][x]); // ㅏ
    }
    if (y < N - 1 && x > 0 && x < M - 1) {
        ans = max(ans, paper[y][x] + paper[y][x + 1] + paper[y + 1][x] + paper[y][x - 1]); // ㅜ
    }
    if (y > 0 && y < N - 1 && x > 0) {
        ans = max(ans, paper[y][x] + paper[y - 1][x] + paper[y + 1][x] + paper[y][x - 1]); // ㅓ
    }
}

void dfs(int y, int x, int cnt, int sum) {
    if (cnt == 4) {
        ans = max(ans, sum);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];
        
        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) {
            continue;
        }
        if (visited[nextY][nextX]) {
            continue;
        }
        
        visited[nextY][nextX] = true;
        dfs(nextY, nextX, cnt + 1, sum + paper[nextY][nextX]);
        visited[nextY][nextX] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }
    
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            checkTshape(i, j);
            
            visited[i][j] = true;
            dfs(i, j, 1, paper[i][j]);
            visited[i][j] = false;
        }
    }
    
    cout << ans;
    return 0;
}